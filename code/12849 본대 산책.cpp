#include <bits/stdc++.h>
//////////////////////////////////////////////
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define fr(i, j, k) for (int i = j; i < k; i++)
#define rfr(i, j, k) for (int i = j - 1; i >= k; i--)
#define A first
#define B second
using namespace std;
void fastIO();
void fileIO();
///////////////////////////////////////////////
/*
    dp
    각 위치에서 생각해보면
    이자리에 오기전까지의 경우의 수를 더해주면 된다

*/
///////////////////////////////////////////////

void preprocess() {
}
long long dp[10];
void solve() {
    int n;
    long long mod = 1e9 + 7;
    cin >> n;
    fill(dp, dp + 10, 0);
    dp[1] = 1;
    long long arr[10] = {
        0,
    };
    arr[1] = 1;
    fr(i, 0, n) {
        dp[1] = (arr[2] % mod + arr[3] % mod) % mod;
        dp[2] = (arr[1] % mod + arr[3] % mod + arr[4] % mod) % mod;
        dp[3] = (arr[1] % mod + arr[2] % mod + arr[4] % mod + arr[5] % mod) % mod;
        dp[4] = (arr[2] % mod + arr[3] % mod + arr[5] % mod + arr[6] % mod) % mod;
        dp[5] = (arr[3] % mod + arr[4] % mod + arr[6] % mod + arr[8] % mod) % mod;
        dp[6] = (arr[4] % mod + arr[5] % mod + arr[7] % mod) % mod;
        dp[7] = (arr[6] % mod + arr[8] % mod) % mod;
        dp[8] = (arr[5] % mod + arr[7] % mod) % mod;
        // fr(j, 1, 9) {
        //     cout << dp[j] << " ";
        // }
        // cout << '\n';
        fr(j, 1, 9) {
            arr[j] = dp[j];
        }
    }
    cout << dp[1];
}
int main() {
    fastIO();
    preprocess();
    // fileIO();
    int T;
    T = 1;
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        // cout << "Case #" << T << ": ";
        solve();
    }
}

///////////////////////////////////////////////
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}