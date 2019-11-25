#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "exercise.hpp"

ContestExerciseImpl::ContestExerciseImpl() : Exercise() {}

bool    is_vowel(char c) {
    return(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
}

void ContestExerciseImpl::main() {
    int n;
    string  s;

    cin >> n;

    vector<string> m;
    vector<string>::iterator it;

    while (n--) {
        cin >> s;

        if (s.length() > 4 && s.length() < 8
            && s[1] - s[0] == 1
            && is_vowel(s[s.length() - 1]))
            m.push_back(s);
    }

    it = std::unique(m.begin(), m.end());
    m.resize(std::distance(m.begin(), it));

    cout << m.size();
}
