#include <bits/stdc++.h>

using namespace std;

// dp
// 동전

// 동전 0을 만드는 가짓수는 1이다 -> 기저사례
// dp[3] += dp[3-1] 1원을 이용해 3 원을 만드는 가짓수
// dp[3] += dp[3-2] 2원을 이용해 3 원을 만드는 가짓수
// dp[3] += dp[3-3] 3원을 이용해 3 원을 만드는 가짓수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        vector<int> v(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        cin >> m;
        vector<int> dp(m + 1);
        dp[0] = 1;
        // dp 테이블 만듬
        // j = 0 부터 m-coin[i] 까지 탐색
        for (int i = 1; i <= n; i++) {
            for (int j = v[i]; j <= m; j++) {
                dp[j] += dp[j - v[i]];
            }
        }
        cout << dp[m] << '\n';
    }
}