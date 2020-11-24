#include <bits/stdc++.h>

using namespace std;

// 이분탐색 파라메트릭서치
// 공유기의 가능한 값을 이분탐색한다..
//  n*logm 의 시간복잡도로 통과가능하다

// 아예 다른쪽으로 생각하고있었다.. ㅠㅠ
// 집 사이의 거리를 lower_bound로 구하려고했고
// 시간복잡도가 nlogn*m으로 통과될줄았고
// 알고보니 logm이라고 생각했던 20만/1 +... +20만/20만은 값이 생각보다 컸고
// 지수적으로 작아지는게 아니었고
// 로그 m도 아니었고 250만이었고
// 멘탙이 나갔고

int n, m;
vector<int> v;
bool check(int k) {
    int prev = v[0], cnt = 1;
    for (int i = 1; i < n; i++) {
        if (v[i] - prev >= k) {
            cnt++;
            prev = v[i];
        }
    }
    return cnt >= m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int r = v[v.size() - 1] - v[0];
    int l = 1;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = max(ans, mid);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
}