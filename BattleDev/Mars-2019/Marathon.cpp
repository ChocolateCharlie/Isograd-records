#include <iostream>
#include <limits>
#include <sstream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int c, b, l;

    cin >> c;

    for (int i = 1; i < 43; i++) {
        cin >> l >> b;
        c = c + l - b;
    }

    if (c <= 100)   cout << 1000;
    else if (c <= 10000)    cout << 100;
    else    cout << "KO";
}
