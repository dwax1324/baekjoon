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
    3차원
    가로세로 조심
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
void preprocess() {
}

int arr[201][201];
vector<pii> dxy = {
    {2, 1},
    {2, -1},
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2},
    {-2, 1},
    {-2, -1}};
vector<pii> dxy2 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int vi[201][201][31];
int n, m;

void print() {
    cout << '\n';
    ror(i, 0, n) {
        ror(j, 0, m) {
            cout << vi[i][j][0] << " ";
        }
        cout << '\n';
    }
}

void bfs(int y, int x, int k) {
    queue<pipii> q;
    q.push({k, {y, x}});
    vi[y][x][k] = 1;
    while (sz(q)) {
        int cury = q.front().S.F;
        int curx = q.front().S.S;
        int cur = q.front().F;
        // print();
        q.pop();
        // error(cur);
        if (cury == n - 1 && curx == m - 1) {
            cout << vi[cury][curx][cur] - 1;
            exit(0);
        }
        if (cur) {
            ror(i, 0, 8) {
                int ny = cury + dxy[i].F;
                int nx = curx + dxy[i].S;
                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (arr[ny][nx] == 1) continue;
                if (vi[ny][nx][cur - 1]) continue;
                vi[ny][nx][cur - 1] = vi[cury][curx][cur] + 1;
                q.push({cur - 1, {ny, nx}});
            }
        }
        ror(i, 0, 4) {
            int ny = cury + dxy2[i].F;
            int nx = curx + dxy2[i].S;
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == 1) continue;
            if (vi[ny][nx][cur]) continue;
            vi[ny][nx][cur] = vi[cury][curx][cur] + 1;
            q.push({cur, {ny, nx}});
            // error(ny, nx);
        }
    }
}

void solve() {
    int k;
    cin >> k;
    cin >> m >> n;
    ror(i, 0, n) {
        ror(j, 0, m) {
            cin >> arr[i][j];
        }
    }

    bfs(0, 0, k);
    cout << -1;
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