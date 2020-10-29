#include <iostream>
#include <limits>
#include <math.h>
#include <sstream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int     b, N, p;
    float   t, a;

    t = 0.0;
    cin >> b >> N;

    for (int i = 0; i < N; i++) {
        cin >> p;
        
        a = p * b;
        
        if (p > 9)      a = a * 70.0 / 100.0;
        else if (p > 5) a = a * 80.0 / 100.0;
        else if (p > 3) a = a * 90.0 / 100.0;
        
        t += a;
    }
    
    cout << ceil(t);
}
