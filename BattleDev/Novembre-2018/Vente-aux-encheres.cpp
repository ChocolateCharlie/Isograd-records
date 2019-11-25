#include <iostream>
#include <string>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int n, r;
    int p;
    string e, f;

    e = "";
    cin >> n >> r;

    while (n--) {
        cin >> p >> f;
        if (p > r) {
            r = p;
            e = f;
        }
    }

    cout << (e == "" ? "KO" : e);
}
