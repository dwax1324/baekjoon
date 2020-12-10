#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<int, char>
#define pipii pair<int, pii>
#define pll pair<long, long>
#define sz(x) (int)(x).size()
#define ff(begin, i, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
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
    기하 구현
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
int arr[101][101];
bool vi[101][101];
int dxy[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
int cnt = 0;
void go(int y, int x) {
    if (y < 0 || x < 0 || y >= 100 || x >= 100) return;
    if (vi[y][x]) return;
    vi[y][x] = true;
    int temp = 0;
    ff(0, i, 4) {
        int ny = y + dxy[i][0];
        int nx = x + dxy[i][1];
        if (arr[y][x] == 1 && arr[ny][nx] == 0) temp++;
    }
    if (temp == 1)
        cnt++;
    else if (temp == 2)
        cnt += 2;
    ff(0, i, 4) {
        int ny = y + dxy[i][0];
        int nx = x + dxy[i][1];
        go(ny, nx);
    }
}

void solve() {
    int n;
    cin >> n;
    ff(0, i, n) {
        int x, y;
        cin >> x >> y;

        ff(y, j, y + 10)
            ff(x, k, x + 10)
                arr[j][k] = 1;
    }

    ff(0, i, 101) {
        ff(0, j, 101) {
            if (arr[i][j] == 1 && !vi[i][j])
                go(i, j);
        }
    }
    cout << cnt;
}

auto main() -> int {
    fastio;
    debug;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    int t = 1;
    // cin >> t;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << i << ": ";
        solve();
    }
}

// do you read the problem properly?
// are the number of the input correct?
// are there edge cases?
// how about overflow?
// data structres properly reset between test cases?
// floating points?
// check if fastio is causing the problem
// use feynman algorithm
