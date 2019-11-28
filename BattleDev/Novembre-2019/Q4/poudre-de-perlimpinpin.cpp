#include <algorithm>
#include <iostream>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
struct  Product {
    double  v, q;
};

void ContestExerciseImpl::main() {
   int  N, M;
   double   C;
   cin >> N >> M >> C;

   vector<Product>  p(N + M);
   for (int i = 0; i < N; i++) {
       double   a, b;
       cin >> a >> b;
       p[i].v = a / b;
       p[i].q = b;
   }
   for (int i = 0; i < M; i++)  cin >> p[i + N].v >> p[i + N].q;
   sort(p.begin(), p.end(), [](const Product &i, const Product &j) -> bool { return(i.v < j.v); });

    double  ans;
    ans = 0.0;

   while (C > 0 && !p.empty()) {
       if (p.back().q >= C) {
           ans = ans + (C * p.back().v);
           C = 0;
       }
       else {
           ans = ans + (p.back().q * p.back().v);
           C -= p.back().q;
       }

       p.pop_back();
   }

   cout << ans;
}
