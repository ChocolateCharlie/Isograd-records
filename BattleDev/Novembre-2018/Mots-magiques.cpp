#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <string>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int     N;
    string  s;
    set<string> magic;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;
        
        if (s.length() > 4 && s.length() < 8
        && s[1] == s[0] + 1
        && (s.back() == 'a' || s.back() == 'e' || s.back() == 'i' || s.back() == 'o' || s.back() == 'u' || s.back() == 'y')
        && magic.count(s) == 0) {
            magic.insert(s);
        }
    }
    
    cout << magic.size();
}
