#include <iostream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int N;
    int f, p;
    int ans;

    ans = 0;
    cin >> N;

    for (int i = 0; i <= N; i++) {
        cin >> f;

        if (i == 0) p = f;

        if (ans != -1) {
            if (p * 2 == N && f * 2 == N)       ans = -1;
            else if (p * 2 > N && f * 2 < N)    ans++;
            else if (p * 2 < N && f * 2 > N)    ans++;
            else if (f * 2 == N)                ans++;
        }

        p = f;
    }

    if (ans == -1)
        cout << "INF";
    else
        cout << ans;
}
