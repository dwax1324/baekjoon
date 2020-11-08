#include <bits/stdc++.h>

using namespace std;
// 트리를 그려보면 피보나치수열로 귀결된다.
int n;
long long dp[1000001];

int main() {
    scanf("%d", &n);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] % 15746 + dp[i - 2] % 15746) % 15746;
    }
    printf("%lld", dp[n]);
}