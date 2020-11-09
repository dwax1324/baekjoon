#include <bits/stdc++.h>

using namespace std;
// 트리를 그려보면 피보나치수열로 귀결된다.
int n;
long long dp[91];
int cnt = 0;

int main() {
    scanf("%d", &n);
    fill(dp, dp + 91, -1);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    printf("%lld", dp[n]);
}