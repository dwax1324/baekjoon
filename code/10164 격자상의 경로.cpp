#include <bits/stdc++.h>

using namespace std;

// dp

// 일반적인 격자dp문제 + 꼭 통과해야하는 점이있음
// dp를 두번 수행한다.
// 1~ k까지, k~ 끝까지

int dp[20][20];
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = 1;

    int y = (k / m) + 1;
    int x = (k % m);

    // if (k == 0)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (cnt++ == k) {
                y = i;
                x = j;
                break;
            }
        }
    }

    // cout << y << " " << x << '\n';

    for (int i = 1; i <= y; i++) {
        for (int j = 1; j <= x; j++) {
            if (i == 1)
                dp[i][j] = 1;
            else if (j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    for (int i = y; i <= n; i++) {
        for (int j = x; j <= m; j++) {
            if (i == 1)
                dp[i][j] = 1;
            else if (j == 1)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    cout << dp[n][m];
}