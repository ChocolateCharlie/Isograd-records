#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int     N;
    string  s;

    cin >> N >> s;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < s.length(); j += N) {
            cout << s[i+j];
        }
    }
}
