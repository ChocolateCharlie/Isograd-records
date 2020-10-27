#include <iostream>
#include <limits>
#include <map>
#include <string>
#include <sstream>
#include "exercise.hpp"

using namespace std;

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    map<string, int>    colors;
    int     N;
    string  s;
    string  color_1, color_2;
    int     nb_1, nb_2;

    nb_1 = 0;
    nb_2 = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;
        colors[s]++;
        
        if (colors[s] > nb_1) {
            color_1 = s;
            nb_1 = colors[s];
        }
        else if (colors[s] > nb_2) {
            color_2 = s;
            nb_2 = colors[s];
        }
    }

    cout << color_1 << " " << color_2;
    
}
