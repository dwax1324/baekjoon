#include <bits/stdc++.h>
using namespace std;

// 구현 자료구조(맵)

// 규칙에 따라 값을 갱신하면서 최댓값이 목표값을 넘는지 체크
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int w, l, g;
    cin >> w >> l >> g;
    map<string, int> MAP;
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        if (b == "W") {
            MAP[a] = w;
        } else {
            MAP[a] = -l;
        }
    }
    int ans = 0;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (MAP[s])
            ans += MAP[s];
        else
            ans -= l;
        ret = max(ans, ret);
        if (ans < 0)
            ans = 0;
    }
    cout << ((ret >= g) ? "I AM NOT IRONMAN!!" : "I AM IRONMAN!!");
}