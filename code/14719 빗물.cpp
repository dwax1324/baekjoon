#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<int, char>
#define pipii pair<int, pii>
#define pll pair<long, long>
#define tiii tuple<int, int, int>
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
    구현
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
int arr[501][501];
int n, m;
void print() {
    ff(1, i, n + 1) {
        ff(1, j, m + 1) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

void setRainBottom() {
    ff(1, i, m + 1) {
        if (arr[n][i] == 1) continue;
        arr[n][i] = 2;
    }
}

void goUp() {
    ff(1, i, n + 1) {
        ff(1, j, m + 1) {
            if (arr[i][j] == 2) {
                if (i < 0) continue;
                if (arr[i - 1][j] == 1 && (j == 1 || j == m)) {
                    arr[i][j] = 0;
                }
                if (arr[i][j - 1] == 0 || arr[i][j + 1] == 0) {
                    arr[i][j] = 0;
                }
                if (arr[i - 1][j] == 1) continue;
                if (arr[i - 1][j] == 2) continue;
                arr[i - 1][j] = 2;
                arr[i][j] = 0;
            }
        }
    }
}
auto solve() {
    cin >> n >> m;
    vector<int> v(m + 1);
    ff(1, i, m + 1) {
        cin >> v[i];
    }
    ff(1, i, m + 1) {
        ff(1, k, v[i] + 1) {
            arr[k][i] = 1;
        }
    }
    int cnt = 0;
    int MAX = 1000;
    while (1) {
        if (cnt++ > MAX + 1000) break;
        if (cnt < MAX) {
            setRainBottom();
        }
        goUp();
    }
    // print();
    int ans = 0;
    ff(1, i, n + 1) ff(1, j, m + 1) if (arr[i][j] == 2) ans++;
    cout << ans;
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
