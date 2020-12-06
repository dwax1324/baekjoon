#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
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
    dfs/bfs + dp

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
void preprocess() {
}

char arr[1001][1001];
ll dp[1001][1001];
bool vi[1001][1001];
int dxy[4][2] = {1, 0, -1, 0, 0, -1, 0, 1};
int n;
bool dfs(int y, int x) {
    vi[y][x] = true;
    if (y == n - 1 && x == n - 1) {
        // cout << "@@";
        return true;
    }
    bool ret = false;
    ror(i, 0, 4) {
        int ny = y + dxy[i][0];
        int nx = x + dxy[i][1];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (vi[ny][nx]) continue;
        if (arr[ny][nx] == '#') continue;
        ret |= dfs(ny, nx);
    }
    return ret;
}

const ll mod = (1LL << 31) - 1;
void solve() {
    cin >> n;
    ror(i, 0, n) {
        ror(j, 0, n) {
            cin >> arr[i][j];
        }
    }

    ror(i, 0, n) {
        if (arr[0][i] == '#') break;
        dp[0][i] = 1;
    }
    ror(i, 0, n) {
        if (arr[i][0] == '#') break;
        dp[i][0] = 1;
    }

    ror(i, 1, n) {
        ror(j, 1, n) {
            if (arr[i][j] == '#') continue;
            dp[i][j] = (dp[i][j] % mod + dp[i - 1][j] % mod) % mod;
            dp[i][j] = (dp[i][j] % mod + dp[i][j - 1] % mod) % mod;
        }
    }

    // ror(i, 0, n) {
    //     ror(j, 0, n) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    if (dp[n - 1][n - 1]) {
        cout << dp[n - 1][n - 1];
        exit(0);
    }

    if (dfs(0, 0))
        cout << "THE GAME IS A LIE";
    else
        cout << "INCONCEIVABLE";
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