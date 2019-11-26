#include <iostream>
#include <cmath>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    double  p, c;
    int N;
    double  ans;

    ans = 0.0;
    cin >> p >> N;

    while (N--) {
        cin >> c;

        if      (c > 9) ans = ans + ((p * 70.0) / 100.0) * c;
        else if (c > 5) ans = ans + ((p * 80.0) / 100.0) * c;
        else if (c > 3) ans = ans + ((p * 90.0) / 100.0) * c;
        else            ans = ans + (p * c);
    }

    cout << ceil(ans);
}
