// Cette solution peut encore être refusée, mais elle est meilleure.
// --> choisir la poudre ne devrait pas se faire au détriment d'une pierre

#include <algorithm>
#include <iostream>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
struct  Product {
    int     va, p;  // va: valeur absolue (pour les pierres)
    double  vr;     // vr: valeur relative (valeur par gramme)
    bool    s = false;
};

void ContestExerciseImpl::main() {
    int N, M, C;
    cin >> N >> M >> C;

    vector<Product> p(N + M);
    for (int i = 0; i < N; i++) {
        cin >> p[i].va >> p[i].p;
        p[i].vr = (double) p[i].va / (double) p[i].p;
        p[i].s = true;
    }
    for (int i = 0; i < M; i++) cin >> p[i + N].vr >> p[i + N].p;
    sort(p.begin(), p.end(), [](const Product &i, const Product &j) -> bool { return(i.vr < j.vr); });

    int ans;
    ans = 0;

    while (C > 0 && !p.empty()) {
        if (!p.back().s && p.back().p > C) {
            ans += p.back().vr * C;
            C = 0;
        }
        else if (p.back().p <= C) {
            ans = (p.back().s ? ans + p.back().va : ans + p.back().vr * p.back().p);
            C -= p.back().p;
        }

        p.pop_back();
    }

    cout << ans;
}
