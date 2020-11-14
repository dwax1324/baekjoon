#include <bits/stdc++.h>
using namespace std;

// 조합탐색 + set

string s;
set<string> SET;
void go(int depth, int k) {
    if (depth == s.size()) return;
    for (int i = 0; i < s.size(); i++) {
        if (i + k <= s.size())
            SET.insert(s.substr(i, k));
    }
    go(depth + 1, k + 1);
    return;
}

int main() {
    cin >> s;
    go(0, 1);
    cout << SET.size();
}