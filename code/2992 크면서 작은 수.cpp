#include <bits/stdc++.h>

using namespace std;

// 조합탐색

// 중복없는 조합찾기 + 대소비교

bool vi[8];
string s;
vector<int> candidates;
int ans = 1 << 30;
void go(int depth, string k, int n) {
    if (depth == n) {
        if (stoi(k) > stoi(s)) {
            ans = min(ans, stoi(k));
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!vi[i]) {
            vi[i] = true;
            go(depth + 1, k + s[i], n);
            vi[i] = false;
        }
    }
}

int main() {
    cin >> s;
    int n = s.size();
    go(0, "", n);
    cout << ((ans == (1 << 30)) ? 0 : ans);
}