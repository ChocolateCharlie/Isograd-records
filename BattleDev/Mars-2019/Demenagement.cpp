#include <iostream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int n;
    int w, p;
    int ar;

    w = 0;
    ar = 0;
    cin >> n;

    while (n--) {
        cin >> p;
        if (w + p > 100) {
            w = p;
            ar++;
        }
        else    w += p;
    }

    cout << (w > 0 ? ar + 1 : ar);
}
