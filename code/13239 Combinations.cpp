#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define pll pair<long, long>
#define fr(num1, num2, i) for (int i = num1; i < num2; i++)
#define rfr(num1, num2, i) for (int i = num1 - 1; i >= num2; i--)
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
using namespace std;
void fastio();
void 쩜씸나깔껐깥아();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    dp
    파스칼의 삼각형 -> nCr 의 dp버전
    

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int dp[1001][1001];
int mod = 1000000007;
void preprocess() {
    dp[0][0] = 1;
    fr(1, 1001, i) {
        dp[i][0] = 1;
        fr(1, i + 1, j) {
            dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
        }
    }
}

void solve() {
    int n, r;
    cin >> n >> r;
    cout << dp[n][r] << '\n';
}

int main() {
    fastio();
    preprocess();
    쩜씸나깔껐깥아();
    int t;
    t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << t << ": ";
        solve();
    }
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void 쩜씸나깔껐깥아() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}