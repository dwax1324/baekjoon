#include <bits/stdc++.h>

// 전형적인 2차원배열 우,하 DP
// 위에,왼쪽에서 오는 값중에 큰 값을 채택한다.

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[301][301];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int dp[301][301];
    for (int i = 0; i < 301; i++)
        for (int j = 0; j < 301; j++)
            dp[i][j] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j] + arr[i][j], dp[i][j]);
            dp[i][j] = max(dp[i][j - 1] + arr[i][j], dp[i][j]);
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    cout << dp[n][m];
}