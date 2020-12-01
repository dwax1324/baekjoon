#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pipii pair<int, pii>
#define pll pair<long, long>
#define fr(num1, num2, i) for (int i = num1; i < num2; i++)
#define rfr(num1, num2, i) for (int i = num1 - 1; i >= num2; i--)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
using namespace std;
void fastio();
void debug();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    bfs/dfs
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}
char arr[51][51];
bool vi[51][51];
int ans[51][51];
vector<pipii> v;
int n, m;

void go2(int y, int x, int num) {
    if (vi[y][x]) return;
    if (arr[y][x] == '0') return;
    if (y < 0 || x < 0 || y >= n || x >= m) return;
    vi[y][x] = true;
    ans[y][x] = num;
    go2(y + 1, x, num);
    go2(y, x + 1, num);
    go2(y - 1, x, num);
    go2(y, x - 1, num);
}

int cnt;
void go(int y, int x, int depth) {
    if (vi[y][x]) return;
    if (arr[y][x] == '0') return;
    if (y < 0 || x < 0 || y >= n || x >= m) return;
    vi[y][x] = true;
    cnt++;
    go(y + 1, x, depth + 1), go(y, x + 1, depth + 1), go(y - 1, x, depth + 1), go(y, x - 1, depth + 1);
}
void solve() {
    cin >> n >> m;
    fr(0, n, i) {
        fr(0, m, j) {
            cin >> arr[i][j];
        }
    }

    fr(0, n, i) {
        fr(0, m, j) {
            if (arr[i][j] == '1' && !vi[i][j]) {
                cnt = 0;
                go(i, j, 0);
                v.push_back({cnt, {i, j}});
            }
        }
    }
    sort(all(v));
    memset(vi, 0, sizeof(vi));
    fr(0, sz(v), i) {
        int y = v[i].S.F;
        int x = v[i].S.S;
        go2(y, x, i + 1);
    }

    fr(0, n, i) {
        fr(0, m, j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
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