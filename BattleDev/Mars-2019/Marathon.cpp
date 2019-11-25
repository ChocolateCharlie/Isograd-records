#include <iostream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int c;
    int bm, am;

    cin >> c;

    for (int i = 2; i <= 43; i++) {
        cin >> bm >> am;
        c = c - am + bm;
    }

    if      (c <= 100)      cout << 1000;
    else if (c <= 10000)    cout << 100;
    else                    cout << "KO";
}
