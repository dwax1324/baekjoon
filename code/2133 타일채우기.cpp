#include <bits/stdc++.h>

using namespace std;

long long dp[31];
int main() {
    int n;
    scanf("%d", &n);

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = 3 * dp[i - 2];
            for (int j = i - 4; j >= 0; j -= 2) {
                dp[i] += dp[j] * 2;
            }
        }
    }
    printf("%lld", dp[n]);
}