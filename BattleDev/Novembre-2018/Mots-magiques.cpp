#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <set>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int N;
    string  S;
    set<string> ans;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> S;
        
        if (S.length() > 4 && S.length() < 8 && S[0] == S[1] - 1 &&
        (S.back() == 'a' || S.back() == 'e' || S.back() == 'i' || S.back() == 'o' || S.back() == 'u' || S.back() == 'y') && ans.count(S) == 0) {
            ans.insert(S);
        }
    }
    
    cout << ans.size();
}
