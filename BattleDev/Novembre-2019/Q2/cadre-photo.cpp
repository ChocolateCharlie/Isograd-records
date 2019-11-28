#include <iostream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int a, b, c, d, e;

    cin >> a >> b >> c >> d;
    e = min(min(min(a, b), c), d);

    cout << (a - e) + (b - e) + (c - e) + (d - e);
}
