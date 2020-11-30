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
void debug();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    dfs/bfs
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}
char arr[751][751];
bool vi[751][751];
int dxy[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int n, m;
int cnt;
void go(int y, int x) {
    if (arr[y][x] == '*') return;
    if (y < 0 || x < 0 || y >= n || x >= m) return;
    if (vi[y][x]) return;
    vi[y][x] = true;
    cnt++;
    fr(0, 8, i) {
        int ny = y + dxy[i][0];
        int nx = x + dxy[i][1];
        go(ny, nx);
    }
}

void solve() {
    cin >> m >> n;

    fr(0, n, i) {
        fr(0, m, j) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    fr(0, n, i) {
        fr(0, m, j) {
            if (arr[i][j] != '*' && !vi[i][j]) {
                cnt = 0;
                go(i, j);
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans;
}
int main() {
    fastio(), debug(), preprocess();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << t << ": ";
        solve();
    }
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
void fastio() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
}

void debug() {
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
}