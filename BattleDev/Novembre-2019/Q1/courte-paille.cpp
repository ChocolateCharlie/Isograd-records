#include <iostream>
#include <limits>
#include <string>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int     N;
    int     t, t_ans;
    string  p, ans;

    t_ans = numeric_limits<int>::max();
    ans = "";
    cin >> N;

    while (N--) {
        cin >> p >> t;

        if (t < t_ans) {
            t_ans = t;
            ans = p;
        }
    }

    cout << ans;
}
