#include <iostream>
#include <limits>
#include <math.h>
#include <sstream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int N, f, r, s;
    int m, b;
    
    b = -1;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> f >> r >> s;
        
        m = ceil((f + r + s) / 3.0);
        if (m > b)  b = m;
    }
    
    cout << b;
}
