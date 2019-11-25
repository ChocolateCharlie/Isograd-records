#include <iostream>
#include <string>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
    int  n;
    string   sol;

    sol = "";
    cin >> n;

    char grid[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'o')  sol += "x";
            if (j < n - 1)          sol += ">";
        }

        for (int j = 1; j < n; j++) sol += "<";
        if (i < n - 1)              sol += "v";
    }

    for (int i = n - 1; i > -1; i--) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*')  sol += "x";
            if (j < n - 1)          sol += ">";
        }
        for (int j = 1; j < n; j++) sol += "<";
        if (i > 0)                  sol += "^";
    }

    cout << sol;
}
