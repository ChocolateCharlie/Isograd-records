#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>
#include "exercise.hpp"

using namespace std;

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

struct  Student {
    int c1, c2;
};

int max_students(vector<Student> &s, vector<bool> &h, int n, int c) {
    bool    m;

    m = false;

    if (c == 1 && h[s[n].c1] == false && h[s[n].c1 + 60] == false)  { m = true; }
    if (c == 2 && h[s[n].c2] == false && h[s[n].c2 + 60] == false)  { m = true; }

    if (n == 0) { return(m ? 1 : 0); }
    
    vector<bool>    h1;
    vector<bool>    h2;
    
    h1.assign(h.begin(), h.end());
    h2.assign(h.begin(), h.end());

    if (m == true) {
        for (int j = 0; j <= 60; j++) {
            if (c == 1) {
                h1[s[n].c1 + j] = true;
                h2[s[n].c1 + j] = true;
            }
            if (c == 2) {
                h1[s[n].c2 + j] = true;
                h2[s[n].c2 + j] = true;
            }
        }
    }

    return((max(max_students(s, h1, n - 1, 1), max_students(s, h2, n - 1, 2))) + (m ? 1 : 0));
}

void ContestExerciseImpl::main() {
    int N;
    vector<bool>    h(1001, false);
    cin >> N;
    vector<Student> s(N);

    for (int i = 0; i < N; i++) {
        cin >> s[i].c1 >> s[i].c2;
    }

    cout << max(max_students(s, h, N - 1, 1), max_students(s, h, N - 1, 2));

}

