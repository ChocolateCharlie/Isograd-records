#include <iostream>
#include <cmath>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int ans;
    int N;
    double n, sa, se;

    ans = 0;
    cin >> N;

    while (N--) {
        cin >> n >> sa >> se;

        if (ceil((n + sa + se) / 3) > ans)
            ans = ceil((n + sa + se) / 3);
    }

    cout << ans;
}
