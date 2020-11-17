#include <bits/stdc++.h>

using namespace std;
#define MAX 1000001
const int mod = 1e9;
int dp[MAX];

// 피보나치의 응용
// 음수의 피보나치의 규칙성을 발견한다
// 짝수면 음수 홀수면 양수

// 짝수 홀수 판별하는데 음수갖고 모듈레이트해서
// 틀렸습니다 엄청받음..

int main() {
    dp[0] = 0;
    dp[1] = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= abs(n); i++) {
        dp[i] = (dp[i - 1] % mod + dp[i - 2] % mod) % mod;
    }
    if (n < 0 && n % 2 == 0) {
        cout << -1 << '\n';
        cout << dp[abs(n)];
    } else if ((n < 0 && abs(n) % 2 == 1) || (n > 0)) {
        cout << 1 << '\n';
        cout << dp[abs(n)];
    } else if (n == 0) {
        cout << 0 << '\n';
        cout << dp[abs(n)];
    }
}