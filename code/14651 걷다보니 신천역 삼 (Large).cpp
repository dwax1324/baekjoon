#include <bits/stdc++.h>
//////////////////////////////////////////////
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define fr(i, num1, num2) for (int i = num1; i < num2; i++)
#define rfr(i, num1, num2) for (int i = num1 - 1; i >= num2; i--)
#define a first
#define b second
using namespace std;
void fastio();
void DEBUG();
///////////////////////////////////////////////
/*
    dp
    dp[1] = 2개 base case
    그 뒤에 자릿수가 하나씩 추가되는데
    0,1,2 가 들어갈 수 있어 이전dp[i]에 3을 곱해주면 된다.

*/
///////////////////////////////////////////////

void preprocess() {
}

long long dp[40001];
int mod = 1e9 + 9;
void solve() {
    int a;
    cin >> a;
    dp[1] = 0;
    dp[2] = 2;
    fr(i, 3, 33334) {
        dp[i] = ((dp[i - 1] % mod) * (3 % mod)) % mod;
        // cout << dp[i] << '\n';
    }
    cout << dp[a];
}
int main() {
    fastio();
    preprocess();
    // DEBUG();
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