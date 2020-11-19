#include <bits/stdc++.h>

using namespace std;

// 스위핑 그리디 수학
// 정렬한다.
// 웅덩이는 이전 웅덩이에 영향을 받는다.
// 추가되는 길이만큼 다음 웅덩이의 시작지점으로 삼는다.
// 웅덩이와 길이가 나누어 떨어지면 그냥 더해준다.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    int ans = 0;
    int nxt = -1;
    for (int i = 0; i < v.size(); i++) {
        if (nxt != -1) {
            if (nxt >= v[i].second - 1) continue;
            if (nxt >= v[i].first) {
                v[i].first = nxt + 1;
            }
        }
        int len = v[i].second - v[i].first;
        int val = 0;
        if (len % l != 0) {
            ans += (len / l) + 1;
            nxt = v[i].second - 1 + l * ((len / l) + 1) - len;
        } else {
            ans += (len / l);
            nxt = v[i].second - 1;
        }
    }

    cout << ans;
}