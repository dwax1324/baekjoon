#include <bits/stdc++.h>
//////////////////////////////////////////////
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define fr(i, num1, num2) for (int i = num1; i < num2; i++)
#define rfr(i, num1, num2) for (int i = num1 - 1; i >= num2; i--)
#define F first
#define S second
using namespace std;
void fastio();
void DEBUG();
///////////////////////////////////////////////
/*
    dp

    dp[i] = dp[i-1] + dp[i-m]
*/
///////////////////////////////////////////////

void preprocess() {
}

int dp[10001];
void solve() {
    int n, m;
    cin >> n >> m;

    dp[0] = 1;
    int mod = 1e9 + 7;
    fr(i, 1, n + 1) {
        dp[i] = dp[i - 1];
        if (i - m >= 0) dp[i] = (dp[i] % mod + dp[i - m] % mod) % mod;
    }
    cout << dp[n];
}
int main() {
    fastio();
    preprocess();
    DEBUG();
    int t;
    t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << t << ": ";
        solve();
    }
}

///////////////////////////////////////////////
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DEBUG() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}