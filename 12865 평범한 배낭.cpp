#include <bits/stdc++.h>

using namespace std;

int dp[101][100001];
vector<pair<int, int>> v;

// 냅색문제

// 무게, 가격 테이블을 만들어서
// 현재 무게가 배낭의 무게를 초과하면 넣지않고
// 아니라면 넣는다.
// 넣지않음과 넣었을 때의 가격을 비교한다.
// DP[i][j]=DP[i][j-해당차례 물건 무게]+해당차례 물건 가치
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int w = v[i - 1].first;
            int p = v[i - 1].second;
            if (w > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + p);
        }
    }
    cout << dp[n][k];
}