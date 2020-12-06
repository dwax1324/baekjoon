#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<int, char>
#define pipii pair<int, pii>
#define pll pair<long, long>
#define ror(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
        cout << '\n';                            \
    }
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << ' ';
    err(++it, args...);
}
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

    dist배열을 3차원으로 생각

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
void preprocess() {
}
int vi[101][101][3];
char arr[101][101];
int dxy[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int n, m;
void bfs(int y, int x, int c) {
    queue<pii> q;
    q.push({y, x});
    vi[y][x][c] = 1;
    while (q.size()) {
        int curY = q.front().F;
        int curX = q.front().S;
        q.pop();
        ror(i, 0, 4) {
            int ny = curY + dxy[i][0];
            int nx = curX + dxy[i][1];
            if (ny < 1 || nx < 1 || ny >= n + 1 || nx >= m + 1) continue;
            if (vi[ny][nx][c]) continue;
            if (arr[ny][nx] == '1') continue;
            vi[ny][nx][c] = vi[curY][curX][c] + 1;
            q.push({ny, nx});
        }
    }
}
void solve() {
    cin >> n >> m;
    ror(i, 1, n + 1) {
        ror(j, 1, m + 1) {
            cin >> arr[i][j];
        }
    }
    ror(i, 0, 3) {
        int a, b;
        cin >> a >> b;
        bfs(a, b, i);
    }

    int ans = 1 << 30;

    ror(j, 0, n) {
        ror(k, 0, m) {
            if (vi[j][k][0] && vi[j][k][1] && vi[j][k][2])
                ans = min(ans, max({vi[j][k][0], vi[j][k][1], vi[j][k][2]}));
        }
    }
    int cnt = 0;
    ror(j, 0, n) {
        ror(k, 0, m) {
            if (vi[j][k][0] && vi[j][k][1] && vi[j][k][2])
                if (max({vi[j][k][0], vi[j][k][1], vi[j][k][2]}) == ans) {
                    cnt++;
                }
        }
    }
    if (ans == 1 << 30)
        cout << -1;
    else
        cout << --ans << '\n'
             << cnt;
}

int main() {
    fastio;
    debug;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    int t = 1;
    // cin >> t;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    preprocess();
    ror(i, 0, t) {
        // cout << "case #" << t << ": ";
        solve();
    }
}