// #include <bits/stdc++.h>

// using namespace std;

// #define MAX 1000001

// int arr[MAX];
// int dp(int a) {
//     if (a == 1) {
//         return 0;
//     }
//     if (arr[a]) return arr[a];
//     arr[a] = dp(a - 1) + 1;
//     if (a % 2 == 0) arr[a] = min(dp(a / 2) + 1, arr[a]);
//     if (a % 3 == 0) arr[a] = min(dp(a / 3) + 1, arr[a]);
//     return arr[a];
// }

// int main() {
//     int n;
//     cin >> n;

//     cout << dp(n);
// }

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000001
int dp[MAX];
int main() {
    int n;
    cin >> n;
    fill(dp, dp + MAX, MAX);
    dp[n] = 0;
    for (int i = n; i >= 1; i--) {
        dp[i - 1] = min(dp[i - 1], dp[i] + 1);
        if (i % 2 == 0) dp[i / 2] = min(dp[i / 2], dp[i] + 1);
        if (i % 3 == 0) dp[i / 3] = min(dp[i / 3], dp[i] + 1);
    }
    cout << dp[1];
}