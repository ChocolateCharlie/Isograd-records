#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int     N;
    string  b;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> b;
        if (b.substr(b.length() - 3, 3) != "555") {
            cout << b;
            return;
        }
    }
}
