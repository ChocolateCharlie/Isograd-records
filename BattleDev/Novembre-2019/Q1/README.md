# Question 1: Courte paille

## Présentation du problème
_On vous donne N couples prénom-taille.
L'objectif est d'afficher le prénom de celui qui a la plus petite taille.
L'énoncé vous garanti qu'il n'y aura pas d'ex aequo._

<br/>

## Résolution pas à pas
### Étape 1: lire l'entrée
L'énoncé indique que l'entrée consiste en:
* un entier N entre 10 et 100
* N lignes composées:
    * d'une chaîne de caractères entre 5 et 10 caractères
    * d'un espace
    * d'un entier entre 1 et 1000

Par conséquent, votre code de départ doit ressembler à ceci:
```cpp
#include <iostream>
#include <string>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int     N;
    int     t;  // taille
    string  p;  // prénom

    cin >> N;

    while (N--) {   // Plus concis qu'une boucle for et relativement équivalent
        cin >> p >> t;
    }
}
```
<br/>

### Étape 2: trouver la plus petite taille
Dans un premier temps, on peut assimiler le problème au suivant: trouver le plus petit entier. Pour cela, vous allez devoir créer une variable conservant cette valeur (mettons ```t_ans```) et, à chaque fois que vous lirez un nouvel entier ```t```, vous le comparerez à cette valeur pour vous assurer que c'est bien la plus petite. Si ce n'est pas la plus petite, vous lui attribuerez alors la nouvelle valeur ```t```.
> **Problème: il faut donner une valeur de départ à ```t_ans```.**

> Il y a plusieurs façons de s'y prendre. Une solution que je ne détaillerai pas ici consiste à initialiser ```t_ans``` avec la première valeur qui vous est donnée.

> La solution que je vais vous détailler consiste à donner une valeur qu'on va considérer comme "infinie" à ```t_ans``` pour avoir la certitude que toute valeur ```t``` sera nécessairement plus petite. **Il n'existe évidemment pas de valeur "infinie".**  Cette technique consiste à prendre un nombre très grand, tellement grand que n'importe quel nombre sera plus petit que lui.

Ajoutez ``` #include <limits>``` en haut de votre code, puis créez la variable ```t_ans``` et initialisez la comme suit:
```cpp
int t_ans;
t_ans = numeric_limits<int>::max();
```

C'est beau, n'est-ce pas ? Vous venez d'initialiser ```t_ans```à la valeur maximale que peut prendre un ```int```. Si vous ne comprenez pas ce code, vous pouvez:
* le relire attentivement, car c'est quand même assez explicite
* en lire un peu plus sur [cplusplus.com](http://www.cplusplus.com/reference/limits/numeric_limits/) 

_(oui, désolée, j'admets que ce n'est pas transcendant comme conseils )_

Ensuite, il ne vous reste plus qu'à écrire une petite comparaison dans la boucle et à afficher votre réponse. Votre code devrait donc ressembler à ceci:
```cpp
#include <iostream>
#include <limits>   // Pour utiliser numeric_limits
#include <string>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int     N;
    int     t, t_ans;   // Déclaration de t_ans
    string  p;
    
    t_ans = numeric_limits<int>::max(); // Initialisation de t_ans
    cin >> N;
    
    while (N--) {
        cin >> p >> t;
        
        if (t < t_ans) {    // La petite condition
            t_ans = t;
        }
    }

    cout << t_ans;  // Et on n'oublie pas d'afficher le résultat !
}
```
<br/>

### Étape 3: afficher le prénom
Félicitations, vous avez quasiment résolu le problème ! Maintenant, il ne vous reste plus qu'à afficher le prénom du perdant (celui qui a la plus petite taille). Pour cela, créez une variable ```ans``` qui servira à conserver le prénom. Il vous suffit d'adapter le contenu de ```ans``` à chaque fois que vous changez la valeur de ```t_ans```. Ainsi, le code source de votre solution doit ressembler à ceci:
```cpp
#include <iostream>
#include <limits>
#include <string>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int     N;
    int     t, t_ans;
    string  p, ans; // Déclaration de ans
    
    t_ans = numeric_limits<int>::max();
    ans = "";   // Initialisation de ans à "" (soit rien, ans est vide)
    cin >> N;
    
    while (N--) {
        cin >> p >> t;
        
        if (t < t_ans) {
            t_ans = t;
            ans = p;    // Conserver le prénom du perdant
        }
    }
    
    cout << ans;    // N'oubliez pas d'afficher la réponse !
}
```
