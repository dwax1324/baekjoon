#include <bits/stdc++.h>

// dp
// 문자열의 인덱스로 판별
// 한번 방문한 인덱스는 다시 가지않는다.
// dp배열에 저장
// idx + v[i].size() 를 탐색
// 한번이라도 1이나오면 성공 -> or 연산
// idx ==  n이면 성공

using namespace std;

int a;
string s;
vector<string> v;
bool dp[101];

int go(int idx) {
    if (idx == s.size()) {
        return 1;
    }
    if (dp[idx]) return 0;
    int res = 0;
    dp[idx] = true;
    for (int i = 0; i < a; i++) {
        if (s.size() - idx < v[i].size()) continue;
        if (s.substr(idx, v[i].size()) == v[i]) {
            res |= go(idx + v[i].size());
        }
    }
    return res;
}

int main() {
    cin >> s;
    cin >> a;
    v.resize(a);
    for (int i = 0; i < a; i++) {
        cin >> v[i];
    }
    cout << go(0) << '\n';
}