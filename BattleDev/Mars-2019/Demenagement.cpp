#include <iostream>
#include <limits>
#include <sstream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int N, P, tw, n;
    
    n = 1;
    tw = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> P;

        if (tw + P > 100) {
            n++;
            tw = P;
        }
        else    tw += P;
    }

    cout << n;
}
