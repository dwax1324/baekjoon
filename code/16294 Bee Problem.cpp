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

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
void preprocess() {
}

const int MAX = 1050;
char arr[MAX][MAX];

// 홀,짝별로 처리
int even[6][2] = {1, 0, -1, 0, 0, 1, 0, -1, -1, 1, 1, 1};
int odd[6][2] = {1, 0, -1, 0, 0, 1, 0, -1, 1, -1, -1, -1};
bool vi[MAX][MAX];
int sum;
int h, n, m;
void dfs(int y, int x) {
    vi[y][x] = true;
    sum++;
    ror(i, 0, 6) {
        int ny, nx;
        if (y % 2 == 0) {
            ny = y + even[i][0];
            nx = x + even[i][1];
        } else {
            ny = y + odd[i][0];
            nx = x + odd[i][1];
        }
        if (ny < 1 || nx < 1 || ny >= n + 1 || nx >= m + 1) continue;
        if (vi[ny][nx]) continue;
        if (arr[ny][nx] != '.') continue;
        dfs(ny, nx);
    }
}

void solve() {
    cin >> h >> n >> m;
    ror(i, 1, n + 1) {
        ror(j, 1, m + 1) {
            cin >> arr[i][j];
        }
    }
    vector<int> sums;
    ror(i, 1, n + 1) {
        ror(j, 1, m + 1) {
            if (!vi[i][j] && arr[i][j] == '.') {
                sum = 0;
                dfs(i, j);
                sums.push_back(sum);
            }
        }
    }
    sort(rall(sums));
    int ans = 0, tot = 0;
    ror(i, 0, sz(sums)) {
        if (tot >= h) break;
        tot += sums[i];
        ans++;
    }
    cout << ans;
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