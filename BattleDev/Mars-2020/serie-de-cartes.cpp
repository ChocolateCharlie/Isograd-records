#include <iostream>
#include <limits>
#include <sstream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int N, c, prev_c, max_l, c_l;
    
    max_l = 1;
    c_l = 1;

    cin >> N;
    cin >> prev_c;

    for (int i = 1; i < N; i++) {
        cin >> c;

        if (c == prev_c)    c_l++;
        else {
            if (c_l > max_l)    max_l = c_l;
            c_l = 1;
        }
        
        prev_c = c;
    }

    cout << (c_l > max_l ? c_l : max_l);
}
