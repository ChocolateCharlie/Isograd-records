#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include "exercise.hpp"

using namespace std;

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int N, R, P;
    string  E, W;
    cin >> N >> R;
    
    W = "KO";
    
    for (int i = 0; i < N; i++) {
        cin >> P >> E;
        
        if (P > R)  {
            R = P;
            W = E;
        }
    }
    
    cout << W;
}
