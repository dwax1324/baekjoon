#include <bits/stdc++.h>

using namespace std;

int dp[41];

// 피보나치수열이다.
// 합의 곱칙, 곱의 법칙
// 솔직히 어떻게 피보나치 수열이 나온건지 모르겠다.
// 규칙성은 발견하긴했는데 거의 귀납적이아니라 연역직어있다..ㅋㅋ
// 이런 문제는 어떻게내는거지..

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> v;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    string s = "";
    for (int i = 0; i < n; i++) {
        s += '0';
    }

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        s[a - 1] = '1';
    }
    // for (auto x : s) cout << x << " ";
    int cnt = 0;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') cnt++;
        if (s[i] == '1') {
            ans *= dp[cnt];
            cnt = 0;
        }
    }
    if (cnt) ans *= dp[cnt];
    cout << ans;
}