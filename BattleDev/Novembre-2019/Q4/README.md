# Question 4: Poudre de perlimpinpin

## Présentation du problème
_Il s'agit littéralement du problème du sac à dos (knapsack problem).
Je vous invite à lire l'énoncé pour plus de détails.
La solution que je vais vous proposer utilise un **algorithme glouton**._

_Notez que **cette solution n'est pas parfaite** (elle fait comme s'il était possible de découper les pierres).
Toutefois, elle est suffisante pour réussir la question._

<br/>

## Résolution pas à pas
### Étape 1: lire l'entrée
L'énoncé indique que l'entrée consiste en:
* trois entiers N, M et C entre 1 et 100
* N lignes composées
    * d'un entier entre 1 et 1000
    * d'un espace
    * d'un entier entre 1 et C, donc entre 1 et 100
* M lignes composées
    * d'un entier entre 1 et 100
    * d'un espace
    * d'un entier entre 1 et C, donc entre 1 et 100

Je vous propose de créer une structure qui permettra de représenter les produits, que ce soient des pierres ou des poudres. En effet, cette solution ne fait pas la distinction entre les deux par souci de simplification (c'est d'ailleurs son défaut).
```cpp
struct  Product {
    int v;  // la valeur par gramme du produit
    int q;  // le poids disponible
};
```
Maintenant, votre code de départ devrait ressembler à ceci:
```cpp
#include <iostream>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
struct  Product {
    int v, q;
};

void ContestExerciseImpl::main() {
   int  N, M, C;
   cin >> N >> M >> C;

   vector<Product>   p(N + M);  // vecteur pour les pierres et les poudres indistinctement
   for (int i = 0; i < N; i++) {
       int  a, b;
       cin >> a >> b;
       p[i].v = a / b;  // calculer la valeur de la pierre par gramme
       p[i].q = b;
   }
   for (int i = 0; i < M; i++)  cin >> p[i + N].v >> p[i + N].q;
}
```
Remarques concernant l'utilisation de ```vector```:
* Si vous ne savez pas ce que c'est, je vous recommande **_vivement_** de vous renseigner. Notez qu'il est possible de résoudre l'exercice en utilisant un tableau, et donc que l'ignorance de cette structure ne vous pénalise pas.
* Si vous avez besoin d'un rafraîchissement de mémoire, je vous conseille de jeter un coup d'oeil sur [cplusplus.com](http://www.cplusplus.com/reference/vector/vector/).
* Si vous avez la flemme de faire ce qui est indiqué ci-dessus, mais que vous ne comprenez pas la syntaxe ```vector<Product> p(N + M);```, notez que le ```(N + M)``` est là pour initialiser un vecteur de taille N + M, tout simplement.

<br/>

### Étape 2: se préparer à écrire l'algorithme
Voici l'algorithme que nous allons utiliser pour résoudre le problème:
* tant que la lampe n'est pas pleine et qu'il reste des produits
    * prendre le produit qui a la plus grande valeur par gramme et en mettre un maximum dans la lampe

Avant de vous lancer dans l'écriture de l'algorithme, je vous propose de trier les produits par ordre croissant de valeur par gramme.
En effet, puisqu'à chaque tour de boucle il faudra chercher le produit qui a la plus grande valeur par gramme, ce sera beaucoup plus facile sur un vecteur préalablement trié.

> **Tri des produits**

> Voici comment le faire en une seule ligne:
```cpp
sort(p.begin(), p.end(), [](const Product &i, const Product &j) -> bool { return(i.v < j.v); });
```
> Le début ressemble bien à la fonction [```sort```](http://www.cplusplus.com/reference/algorithm/sort/?kw=sort) du header ```algorithm```. En revanche, la fin vous déroute peut-être: c'est une [expression lambda](https://en.cppreference.com/w/cpp/language/lambda), disponible depuis le C++11.

> _Notez que l'utilisation d'une expression lambda me permet d'effectuer le tri en une seule ligne et donc de gagner du temps.
Toutefois, il était parfaitement possible de résoudre le problème sans l'utiliser en écrivant une fonction de tri comme on le fait "classiquement" avec [sort](http://www.cplusplus.com/reference/algorithm/sort/?kw=sort)._

Votre code devrait maintenant ressembler à ceci:
```cpp
#include <algorithm>    // Pour utiliser sort()
#include <iostream>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
struct  Product {
    int v, q;
};

void ContestExerciseImpl::main() {
   int  N, M, C;
   cin >> N >> M >> C;

   vector<Product>  p(N + M);
   for (int i = 0; i < N; i++) {
       int  a, b;
       cin >> a >> b;
       p[i].v = a / b;
       p[i].q = b;
   }
   for (int i = 0; i < M; i++)  cin >> p[i + N].v >> p[i + N].q;
   sort(p.begin(), p.end(), [](const Product &i, const Product &j) -> bool { return(i.v < j.v); });
}
```
<br/>

### Étape 3: l'algorithme
Je vous invite à reprendre la description de l'algorithme faite au début de la section précédente.
* Comme nous avons trié notre vecteur par ordre croissant, le produit qui a la plus grande valeur par gramme sera toujours le dernier de notre vecteur.
* Pour en mettre un maximum dans la lampe
    1. soit il reste suffisamment de place dans la lampe pour le mettre en entier
    2. soit la place manque, auquel cas on remplira la lampe avec le produit (_pour rappel, cette solution fait comme s'il était possible de couper les pierres_)

Ainsi, le code ressemble à ceci:
```cpp
while (C > 0 && !p.empty()) {   // tant qu'il reste de la place dans la lampe, on a C > 0
    if (p.back().q >= C) {      // s'il y a plus de produit que de place, on met autant de produit qu'il y a de place
        ans = ans + (C * p.back().v);
        C = 0;
    }
    else {                      // si le produit tient en entier dans la lampe, on le met en entier
        ans = ans + (p.back().q * p.back().v);
        C -= p.back().q;
    }
    // Il ne faut pas oublier ensuite de retirer du vecteur le produit utilisé.
    // Avec un tableau, on pourrait utiliser un index pour le parcourir.
       p.pop_back();
   }
```

Voici le code complet à la fin de cette étape:
```cpp
#include <algorithm>
#include <iostream>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
struct  Product {
    int v, q;
};

void ContestExerciseImpl::main() {
   int  N, M, C;
   cin >> N >> M >> C;

   vector<Product>  p(N + M);
   for (int i = 0; i < N; i++) {
       int  a, b;
       cin >> a >> b;
       p[i].v = a / b;
       p[i].q = b;
   }
   for (int i = 0; i < M; i++)  cin >> p[i + N].v >> p[i + N].q;
   sort(p.begin(), p.end(), [](const Product &i, const Product &j) -> bool { return(i.v < j.v); });

    int ans;
    ans = 0;

   while (C > 0 && !p.empty()) {
       if (p.back().q >= C) {
           ans = ans + (C * p.back().v);
           C = 0;
       }
       else {
           ans = ans + (p.back().q * p.back().v);
           C -= p.back().q;
       }

       p.pop_back();
   }

   cout << ans;
}
```
<br/>

### Étape 4: une question de précision
L'algorithme est complet, vous affichez bien une réponse sur la sortie standard mais... ce n'est pas la bonne !
Et pour cause: jusqu'à présent, tout le code utilise des entiers (```int```), d'où une approximation lorsqu'on calcule la valeur par gramme des pierres.
Comme j'étais en temps limité, je ne me suis pas embêtée à caster, et j'ai tout passé en ```double```, ce qui donne:
```cpp
#include <algorithm>
#include <iostream>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
struct  Product {
    double  v, q;
};

void ContestExerciseImpl::main() {
   int  N, M;
   double   C;
   cin >> N >> M >> C;

   vector<Product>  p(N + M);
   for (int i = 0; i < N; i++) {
       double   a, b;
       cin >> a >> b;
       p[i].v = a / b;
       p[i].q = b;
   }
   for (int i = 0; i < M; i++)  cin >> p[i + N].v >> p[i + N].q;
   sort(p.begin(), p.end(), [](const Product &i, const Product &j) -> bool { return(i.v < j.v); });

    double  ans;
    ans = 0.0;

   while (C > 0 && !p.empty()) {
       if (p.back().q >= C) {
           ans = ans + (C * p.back().v);
           C = 0;
       }
       else {
           ans = ans + (p.back().q * p.back().v);
           C -= p.back().q;
       }

       p.pop_back();
   }

   cout << ans;
}
```

Je me suis arrêtée à cette étape durant la compétition car ce code m'a permis d'accéder à la 5ème question. Pour autant, **je vous rappelle que cette solution n'est pas parfaite, et peu parfois vous être refusée.** En effet, ici, les pierres sont considérées comme des poudres et peuvent ainsi être coupées, or ce n'est pas le cas.
