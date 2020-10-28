#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int     N, r, P;
    string  w, E;

    w = "KO";
    cin >> N >> r;

    for (int i = 0; i < N; i++) {
        cin >> P >> E;
        
        if (P > r) {
            r = P;
            w = E;
        }
    }
    
    cout << w;
}
