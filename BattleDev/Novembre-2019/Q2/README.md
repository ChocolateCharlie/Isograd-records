# Question 2: Cadre photo
---

## Présentation du problème
Honnêtement, je n'ai pas très bien compris ce problème et je l'ai résolu en étudiant un peu la sortie attendue en fonction des entrées fournies... Pas terrible comme façon de procéder, surtout pendant une compétition en temps limité.
Voici comment, avec un peu de recul, je l'expliquerais: on vous donne 4 longueurs, et vous vous voulez que ces 4 longueurs soient identiques. Quelle sera la longueur de vos chutes ?

## Résolution pas à pas
**Il était possible de résoudre ce problème de différentes façons. La solution que je vais vous présenter n'est pas la plus élégante, ni la plus efficace.** En particulier, l'utilisation d'un tableau, si vous étiez en temps limité, vous ferait ici gagner du temps.

### Lire l'entrée
L'énoncé indique que l'entrée consiste en:
* 4 entiers entre 1 et 1000

Par conséquent, votre code de départ ressemblera peut-être à ceci:
```cpp
#include <iostream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int a, b, c, d;

    cin >> a >> b >> c >> d;
}
```

### Trouver la plus petite longueur
L'objectif est de couper des planches afin qu'elles aient toutes la même longueur. Il est évidemment impossible de rallonger la longueur d'une planche, donc toutes vos planches auront la même longueur que la plus petite des planches. Ainsi, vous allez créer une nouvelle variable, mettons ```e```, et y stocker la plus petite longueur.
Voici mon code pour cette étape, mais on peut imaginer pas mal de variantes qui fonctionneraient également:
```cpp
    e = min(min(min(a, b), c), d);
```
_Notez qu'en emboîtant les fonctions de manière répétitive, il est possible d'oublier de fermer une parenthèse ou de faire une erreur qui peut bêtement vous faire perdre du temps en compétition si vous ne la voyez pas tout de suite Ici, il n'y avait que 4 variables et ça tient en une ligne, alors ça reste lisible et suffisamment rapide à mon goût._

### Calculer la longueur totale des chutes
Pour chaque planche, seule la longueur de la plus petite planche (conservée dans ```e```) sera utilisée. Par conséquent, la longueur de la chute d'une planche est ```longueur de la planche - e```. Pour résoudre le problème, il faut afficher la somme des chutes de chaque planche.
Voici la solution que je propose:
```cpp
#include <iostream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int a, b, c, d, e;

    cin >> a >> b >> c >> d;
    e = min(min(min(a, b), c), d);

    cout << (a - e) + (b - e) + (c - e) + (d - e);
}
```
En une ligne, je fais les soustractions, les additions et l'affichage. Toutefois:
* ce n'est pas très rapide à écrire
* si j'avais fait une erreur (de signe, de parenthèse...), ce n'est pas ce qu'il y a de plus rapide à débugger