#include <iostream>
#include <limits>
#include <sstream>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

void ContestExerciseImpl::main() {
   int  N, prev, c, f;
   bool inf;
   cin >> N;
   
   c = 0;
   inf = false;
   cin >> prev;
   cerr << N << endl;
   
   for (int i = 0; i < N; i++) {
       cin >> f;
       
       if (((prev > (N + 1) / 2) && (f < N / 2))
       || ((prev < N / 2) && (f > (N + 1) / 2))) {
           c++;
           cerr << prev << " " << f << " " << N / 2 << endl;
       }
       if (N % 2 == 0 && f ==  N / 2) {
           if (prev == N / 2) {
               inf = true;
               cerr << "INF detected";
           }
           else { c++; }
       }
       
       prev = f;
       
       
   }
   
   if (inf) cout << "INF";
   else     cout << c;
}
