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
    bfs
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

char arr[101][101];
int vi[101][101];
int dxy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void solve() {
    int n, m;
    cin >> n >> m;
    queue<pii> q;
    int ty, tx;
    fr(0, n, i) {
        fr(0, m, j) {
            cin >> arr[i][j];
            if (arr[i][j] == 'C') {
                q.push({i, j});
                vi[i][j] = 1;
            }
            if (arr[i][j] == 'B') {
                ty = i, tx = j;
            }
        }
    }

    while (q.size()) {
        int curX = q.front().S;
        int curY = q.front().F;
        q.pop();
        fr(0, 4, i) {
            int ny = curY + dxy[i][0];
            int nx = curX + dxy[i][1];
            if (vi[ny][nx] != 0) continue;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == '*') continue;
            q.push({ny, nx});
            vi[ny][nx] = vi[curY][curX] + 1;
        }
    }
    cout << vi[ty][tx] - 1;
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