#include <algorithm>
#include <iostream>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
struct  Product {
    double  v, q;
    bool    stone = false;
    int     stone_val;
};

void ContestExerciseImpl::main() {
   int  N, M, C;
   cin >> N >> M >> C;

   vector<Product>  p(N + M);
   for (int i = 0; i < N; i++) {
       double   a, b;
       cin >> a >> b;
       p[i].v = a / b;
       p[i].q = b;
       p[i].stone = true;
       p[i].stone_val = a;
   }
   for (int i = 0; i < M; i++)  cin >> p[i + N].v >> p[i + N].q;
   sort(p.begin(), p.end(), [](const Product &i, const Product &j) -> bool { return(i.v < j.v); });

    int ans;
    ans = 0;

   while (C > 0 && !p.empty()) {
       if (p.back().q > C) {
           if (!p.back().stone) {
               ans = ans + (C * p.back().v);
               C = 0;
           }
       }
       else {
           if (p.back().stone)  ans += p.back().stone_val;
           else                 ans = ans + (p.back().q * p.back().v);
           C -= p.back().q;
       }

       p.pop_back();
   }

   cout << ans;
}
