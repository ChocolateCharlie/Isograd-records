#include <iostream>
#include <string>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}
// Global variables
vector<string>  g_t;
string  g_ans = "";

// Functions
bool    substr(string &x, string &y) {
    int i;

    i = 0;

    for (char c : y) {
        if (i < x.size() && x[i] == c)  i++;
    }

    return(i == x.size());
}

bool    valid(string s) {
    for (string x : g_t) {
        if (!substr(s, x))  return(false);
    }
    return(true);
}

void    strtest(int i, string s) {
    if (i == 10) {
        if (valid(s) && s.size() > g_ans.size()) {
            g_ans = s;
            return;
        }
    }

    strtest(i + 1, s);
    strtest(i + 1, s + g_t[0][i]);
}

// THE MAIN FUNCTION
void ContestExerciseImpl::main() {
    string  s;
    int n;

    cin >> n;
    while (n--) {
        cin >> s;
        g_t.push_back(s);
    }

    strtest(0, "");

    if (g_ans == "")    g_ans = "KO";

    cout << g_ans << endl;
}
