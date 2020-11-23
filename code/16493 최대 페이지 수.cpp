#include <bits/stdc++.h>

using namespace std;

// dp 냅색문제
// 냅색문제 아이디어를 그대로 차용해서 적용하면된다.

int dp[201][6001];
int main() {
    int n, m;
    vector<int> pages;
    vector<int> days;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        days.push_back(a);
        pages.push_back(b);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int d = days[i - 1];
            int p = pages[i - 1];
            if (d > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - d] + p);
            }
        }
    }

    // for (int i = 1; i <= m; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << dp[m][n];
}