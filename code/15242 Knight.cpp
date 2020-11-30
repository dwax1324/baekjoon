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
    bfs
    

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}
void solve() {
    string a, b;
    cin >> a >> b;
    int sy, sx, ty, tx;
    sy = a[0] - 'a';
    sx = a[1] - '1';
    ty = b[0] - 'a';
    tx = b[1] - '1';
    // cout << sy << " " << sx << " " << ty << " " << tx << "\n";
    int dxy[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
    queue<pii> q;
    int vi[10][10];
    memset(vi, 0, sizeof(vi));
    q.push({sy, sx});
    vi[sy][sx] = 1;
    while (q.size()) {
        int curX = q.front().S;
        int curY = q.front().F;
        q.pop();
        fr(0, 8, i) {
            int ny = curY + dxy[i][1];
            int nx = curX + dxy[i][0];
            if (vi[ny][nx]) continue;
            if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8) continue;
            q.push({ny, nx});
            vi[ny][nx] = vi[curY][curX] + 1;
            // cout << curY << " " << curX << '\n';
            // cout << dxy[i][1] << " " << dxy[i][0] << '\n';
            // cout << ny << " " << nx << '\n';
            //     fr(0, 8, i) {
            //         fr(0, 8, j) {
            //             cout << vi[i][j] << " ";
            //         }
            //         cout << '\n';
            //     }
            //     cout << '\n';
        }
    }
    cout << vi[ty][tx] - 1;
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