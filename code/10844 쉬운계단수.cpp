#include <bits/stdc++.h>
// 1의 자리수를 제외한 자리의 가짓수를 계산한다.
// 각 자리에 0이오면 1의 dp를, 9가오면 8의 dp를 가져온다.
// 나머지는 앞,뒤의 dp를 가져온다.
// 마지막으로 1의자리수를 더해준다(1~9)

using namespace std;

int main() {
    int n;
    cin >> n;
    int mod = 1e9;
    int dp[101][10];

    for (int i = 0; i < 10; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][1];
            else if (j == 9)
                dp[i][j] = dp[i - 1][8];
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
        }
    }

    int sum = 0;
    for (int i = 1; i < 10; i++) {
        sum = (dp[n][i] % mod + sum % mod) % mod;
    }
    cout << sum;
}