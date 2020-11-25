#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int n, s, m;

//dp
// bool dp[i][j] i번째 음악이 j번째 음량으로 재생될 수 있는지?
// dp테이블 채우고나서 마지막번째음량의 최댓값을 출력하면된다.

bool dp[110][1010];

bool go(int depth, int cur) {
    if (cur > m || cur < 0) return dp[depth][cur] = 0;
    if (depth == n + 1) {
        return dp[depth][cur] = 1;
    }
    if (dp[depth][cur] == 1) return dp[depth][cur];
    dp[depth][cur] = 1;
    go(depth + 1, cur + v[depth]);
    go(depth + 1, cur - v[depth]);
    return 1;
}

int main() {
    cin >> n >> s >> m;
    v.resize(n + 1);
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    go(1, s);
    for (int i = m; i >= 0; i--) {
        if (dp[n + 1][i]) {
            // cout << i;
            // return 0;
        }
    }
    // cout << -1;

    for (int i = 1; i <= n + 1; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << '\n';
    }
}