#include <algorithm>
#include <iostream>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
struct Request {
    int d, f;
};

void ContestExerciseImpl::main() {
    int N, M;
    cin >> N >> M;

    vector<int> c(N);
    for (int i = 0; i < N; i++) c[i] = -1;

    vector<Request> r(M);
    for (int i = 0; i < M; i++) cin >> r[i].d >> r[i].f;
    sort(r.begin(), r.end(), [](const Request &a, const Request &b) -> bool { return(a.d < b.d); });

    bool    req_sat;
    vector<int> ans(M);

    for (int i = 0; i < M; i++) {
        req_sat = false;

        for (int j = 0; j < N; j++) {
            if (c[j] != -1 && r[c[j]].f <= r[i].d)  c[j] = -1;
            if (!req_sat && c[j] == -1) {
                c[j] = i;
                ans[i] = j + 1;
                req_sat = true;
            }
        }

        if (!req_sat) {
            cout << "pas possible";
            return;
        }
    }

   for (int i = 0; i < M; i++)  cout << ans[i] << " ";
}
