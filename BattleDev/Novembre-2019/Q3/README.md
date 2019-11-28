# Question 3: Registered Jack 11
---

## Présentation du problème
Vous disposez de N câbles à distribuer pour satisfaire M requêtes. On vous demande d'afficher une solution (n'importe laquelle) ou, le cas échéant, "pas possible". Paraphraser ici l'énoncé serait une perte de temps, aussi je vous invite à le (re)lire si nécessaire.

## Résolution pas à pas
### Lire l'entrée
L'énoncé indique que l'entrée consiste en:
* un entier N entre 1 et 500
* un entier M entre 1 et 3N, donc entre 1 et 1500
* N lignes composées:
    * d'un entier entre 0 et 2500 représentant une date de début
    * d'un espace
    * d'un entier entre 0 et 2500 représentant une date de fin

Je vous propose de créer une structure qui nous permettra de représenter les requêtes. Cela devrait améliorer la lisibilité du code, même si en concours ce n'est pas forcément un gain de temps.
```cpp
struct Request {
    int d;  // date de début
    int f;  // date de fin
};
```
Maintenant, votre code de départ devrait ressembler à ceci:
```cpp
#include <iostream>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
struct Request {
    int d, f;
};

void ContestExerciseImpl::main() {
    int N, M;
    cin >> N >> M;
    
    vector<Request> r(M);
    for (int i = 0; i < M; i++) cin >> r[i].d >> r[i].f;
}
```
Remarques concernant l'utilisation de ```vector```:
* Si vous ne savez pas ce que c'est, je vous recommande **_vivement_** de vous renseigner. Notez qu'il était possible de résoudre l'exercice en utilisant un tableau, et donc que l'ignorance de cette structure ne vous pénalisait pas.
* Si vous avez besoin d'un rafraîchissement de mémoire, je vous conseille de jeter un coup d'oeil sur [cplusplus.com](http://www.cplusplus.com/reference/vector/vector/).
* Si vous avez la flemme de faire ce qui est indiqué ci-dessus, mais que vous ne comprenez pas la syntaxe ```vector<Request> r(M);```, notez que le ```(M)``` est là pour initialiser un vecteur de taille M, tout simplement.

### Se préparer à écrire l'algorithme
Voici l'algorithme que nous allons utiliser pour résoudre le problème:
* parcourir les requêtes par ordre de date de début ```d``` croissant
* pour chaque requête:
    * "libérer" tous les câbles qui ne sont plus utilisés à la date ```d```
    * si un câble est libre, l'attribuer à la requête
    * si aucun câble n'est libre, interrompre le programme et afficher "pas possible"

Avant de nous lancer dans l'écriture de l'algorithme, je vous propose de:
* trier les requêtes par ordre de date de début ```d``` croissant
* créer un vecteur pour conserver l'état de chaque câble (disponible ou non)
* créer un vecteur pour conserver la suite de câbles utilisés et ainsi pouvoir l'afficher en guise de solution

> **Tri des requêtes**
Voici comment le faire en une seule ligne:
```cpp
sort(r.begin(), r.end(), [](const Request &a, const Request &b) -> bool { return(a.d < b.d); });
```
> Le début ressemble bien à la fonction [```sort```](http://www.cplusplus.com/reference/algorithm/sort/?kw=sort) du header ```algorithm```. En revanche, la fin vous déroute peut-être: c'est une [expression lambda](https://en.cppreference.com/w/cpp/language/lambda), disponible depuis le C++11.
_Notez que l'utilisation d'une expression lambda me permet d'effectuer le tri en une seule ligne et donc de gagner du temps. Toutefois, il était parfaitement possible de résoudre le problème sans l'utiliser en écrivant une fonction de tri comme on le fait "classiquement" avec [sort](http://www.cplusplus.com/reference/algorithm/sort/?kw=sort)._

Votre code devrait maintenant ressembler à ceci:
```cpp
#include <algorithm>    // Pour utiliser sort()
#include <iostream>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
struct Request {
    int d, f;
};

void ContestExerciseImpl::main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> c(N);   // c comme câbles
    for (int i = 0; i < N; i++) c[i] = -1;  // -1 signifie qu'un câble est disponible
    
    vector<Request> r(M);
    for (int i = 0; i < M; i++) cin >> r[i].d >> r[i].f;
    sort(r.begin(), r.end(), [](const Request &a, const Request &b) -> bool { return(a.d < b.d); });

    vector<int> ans(M); // ans comme answer, pour conserver la suite de câbles utilisés 

    // On peut anticiper un peu et écrire l'affichage de la réponse
   for (int i = 0; i < M; i++)  cout << ans[i] << " "; 
}
```

### Le nerf de la guerre: l'algorithme
Pour l'instant, nous allons considérer qu'il est toujours possible de répondre à toutes les requêtes.
Je vous invite à reprendre la description de l'algorithme faite au début de la section précédente.
* Parcourir les requêtes: il suffit d'utiliser une boucle
* Pour chaque requête, "libérer" les câbles qui ne sont plus utilisés: nous allons donc conserver dans notre vecteur de câbles de quoi retrouver la date d'expiration de l'utilisation du câble. Pour ce faire, je vous propose d'utiliser l'index de la requête qui s'est vue attribuer le câble. Ainsi, il nous suffira d'écrire une boucle sur le vecteur de câbles pour vérifier que la requête correspondant à l'index stocké dans pour chaque câble indisponible n'a pas pris fin.
* Si un câble est libre, l'attribuer à la requête: une simple condition suffit.

Ainsi, le code ressemble à ceci:
```cpp
for (int j = 0; j < N; j++) {
    if (c[j] != -1 && r[c[j]].f <= r[i].d) {
        // c[j] != -1           --> le câble n'est pas disponible
        // r[c[j]].f <= r[i].d  --> la date de fin du câble est antérieure ou égale à la date actuelle
        c[j] = -1;
    }
    if (c[j] == -1) {   // le câble est disponible
        c[j] = i;       // on conserve l'index de la requête
        ans[i] = j + 1; // j + 1 car l'index des câbles dans la solution demandée commence à 1, et non à 0
    }
}
```
**Remarque importante:** comme j'ai voulu découper mon code par étapes, il y a un bug. En effet, ici une requête utilise tous les câbles disponibles, même lorsqu'elle se serait déjà vue attribuer un câble... Ce bug sera corrigé plus bas, mais vous pouvez déjà le faire en ajoutant un booléen (par exemple ```if (not_init && c[j] == -1)``` etc.).

Voici le code complet à la fin de cette étape:
```cpp
#include <algorithm>
#include <iostream>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
struct Request {
    int d, f;
};

void ContestExerciseImpl::main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> c(N);
    for (int i = 0; i < N; i++) c[i] = -1;
    
    vector<Request> r(M);
    for (int i = 0; i < M; i++) cin >> r[i].d >> r[i].f;
    sort(r.begin(), r.end(), [](const Request &a, const Request &b) -> bool { return(a.d < b.d); });

    vector<int> ans(M);

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (c[j] != -1 && r[c[j]].f <= r[i].d)  c[j] = -1;
            if (c[j] == -1) {
                c[j] = i;
                ans[i] = j + 1;
            }
        }
    }

   for (int i = 0; i < M; i++)  cout << ans[i] << " "; 
}
```

### Last but not least: gérer les cas "pas possible"
Je vous propose déjà de débugger notre code à l'aide d'un booléen que j'appelerais ```req_sat``` (pour _request satisfied_, mais faites comme vous voulez).
```cpp
for (int i = 0; i < M; i++) {
    req_sat = false;    // nouvelle requête -> pas encore satisfaite

    for (int j = 0; j < N; j++) {
        if (c[j] != -1 && r[c[j]].f <= r[i].d)  c[j] = -1;
        if (!req_sat && c[j] == -1) {   // vérifier que la requête n'a pas déjà été satisfaite avant de lui attribuer un câble
            c[j] = i;
            ans[i] = j + 1;
            req_sat = true; // indiquer que la requête est satisfaite pour éviter de lui attribuer d'autres câbles
        }
    }
}
```
Voilà qui est mieux ! :D
Grâce à ```req_sat```, il est aisé de voir si une requête n'a pas été satisfaite. Or, si c'est le cas, c'est qu'aucun câble n'est diponible, et donc que la réponse est "pas possible".
Voici donc le code final:
```cpp
#include <algorithm>
#include <iostream>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
struct Request {
    int d, f;
};

void ContestExerciseImpl::main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> c(N);
    for (int i = 0; i < N; i++) c[i] = -1;
    
    vector<Request> r(M);
    for (int i = 0; i < M; i++) cin >> r[i].d >> r[i].f;
    sort(r.begin(), r.end(), [](const Request &a, const Request &b) -> bool { return(a.d < b.d); });
    
    bool    req_sat;
    vector<int> ans(M);
    
    for (int i = 0; i < M; i++) {
        req_sat = false;

        for (int j = 0; j < N; j++) {
            if (c[j] != -1 && r[c[j]].f <= r[i].d)  c[j] = -1;
            if (!req_sat && c[j] == -1) {
                c[j] = i;
                ans[i] = j + 1;
                req_sat = true;
            }
        }
        
        if (!req_sat) {
            cout << "pas possible";
            return;
        }
    }
   
   for (int i = 0; i < M; i++)  cout << ans[i] << " "; 
}
```