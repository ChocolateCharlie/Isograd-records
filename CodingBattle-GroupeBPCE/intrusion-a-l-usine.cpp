#include <iostream>
#include <limits>
#include <sstream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int N, p1, v1, p2, v2, p, v;

    cin >> N >> p1 >> v1 >> p2 >> v2;

    if (v1 != v2)   {
        cin >> p >> v;
        cout << (v == v1 ? p2 : p1);
    }
    else {
        for (int i = 0; i < N - 2; i++) {
            cin >> p >> v;
            
            if (v != v1) {
                cout << p;
                return;
            }
        }
    }
    
}
