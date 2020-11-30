#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define pll pair<long, long>
#define fr(num1, num2, i) for (int i = num1; i < num2; i++)
#define rfr(num1, num2, i) for (int i = num1 - 1; i >= num2; i--)
#define F first
#define S second
using namespace std;
void fastio();
void 쩜씸나깔껐깥아();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    bfs
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

bool vi[101][101];
char arr[101][101];
int n, m;
void go(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= m) return;
    if (arr[y][x] == '.') return;
    if (vi[y][x]) return;
    vi[y][x] = true;

    go(y + 1, x);
    go(y - 1, x);
    go(y, x + 1);
    go(y, x - 1);
    go(y + 1, x + 1);
    go(y - 1, x - 1);
    go(y + 1, x - 1);
    go(y - 1, x + 1);
}

void solve() {
    cin >> n >> m;

    fr(0, n, i) {
        fr(0, m, j) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    fr(0, n, i) {
        fr(0, m, j) {
            if (!vi[i][j] && arr[i][j] == '#') {
                cnt++;
                go(i, j);
            }
        }
    }
    cout << cnt;
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