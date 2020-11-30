#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define pll pair<long, long>
#define fr(num1, num2, i) for (int i = num1; i < num2; i++)
#define rfr(num1, num2, i) for (int i = num1 - 1; i >= num2; i--)
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
using namespace std;
void fastio();
void 쩜씸나깔껐깥아();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    dp
    

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}
int arr[100001][3];
int dp[100001][3];
int n;

int go(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= 3) return -1;
    if (y == n - 1) {
        // cout << "@";
        return arr[y][x];
    }
    if (dp[y][x] != -1) return dp[y][x];
    int &ret = dp[y][x];
    return ret = max({ret, go(y + 1, x) + arr[y][x], go(y + 1, x + 1) + arr[y][x], go(y + 1, x - 1) + arr[y][x]});
}

int go2(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= 3) {
        return 1 << 30;
    }
    if (y == n - 1) {
        return arr[y][x];
    }
    if (dp[y][x] != 1 << 30) return dp[y][x];
    int &ret = dp[y][x];
    return ret = min({ret, go2(y + 1, x) + arr[y][x], go2(y + 1, x + 1) + arr[y][x], go2(y + 1, x - 1) + arr[y][x]});
}
void solve() {
    cin >> n;
    fr(0, n, i) {
        fr(0, 3, j) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    fr(0, 3, i) {
        memset(dp, -1, sizeof(dp));
        ans = max(ans, go(0, i));
    }
    int ans2 = (1 << 30);
    fr(0, 3, i) {
        fr(0, n, j) {
            fr(0, 3, k) {
                dp[j][k] = 1 << 30;
            }
        }
        ans2 = min(ans2, go2(0, i));
    }

    cout << ans << " " << ans2;
}

int main() {
    fastio();
    preprocess();
    쩜씸나깔껐깥아();
    int t;
    t = 1;
    // cin >> t;
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