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
#define zz(begin, i, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
int arr[1002][1002];
int dxy[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
bool check(pii& p) {
    int cnt = 0;
    zz(0, i, 4) {
        if (arr[p.F + dxy[i][0]][p.S + dxy[i][1]]) {
            cnt++;
        }
    }
    return cnt == 4;
}

int n, m;
int cnt = 2;
void down(pii& p) {
    if (p.F == n || arr[p.F + 1][p.S]) return;
    p.F++;
    arr[p.F][p.S] = cnt++;
    down(p);
}
void up(pii& p) {
    if (p.F == 1 || arr[p.F - 1][p.S]) return;
    p.F--;
    arr[p.F][p.S] = cnt++;
    up(p);
}
void left(pii& p) {
    if (p.S == 1 || arr[p.F][p.S - 1]) return;
    p.S--;
    arr[p.F][p.S] = cnt++;
    left(p);
}
void right(pii& p) {
    if (p.S == m || arr[p.F][p.S + 1]) return;
    p.S++;
    arr[p.F][p.S] = cnt++;
    right(p);
}

void solve() {
    cin >> m >> n;
    int k;
    cin >> k;
    pii cur = {1, 1};
    arr[1][1] = 1;
    while (1) {
        if (check(cur)) break;
        down(cur);
        right(cur);
        up(cur);
        left(cur);
    }

    zz(1, i, n + 1) {
        zz(1, j, m + 1) {
            if (arr[i][j] == k) {
                cout << j << " " << i;
                exit(0);
            }
        }
    }
    cout << 0;
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

// what's the point of this problem?
// are the number of the input correct?
// are there edge cases?
// how about overflow?
// data structres properly reset between test cases?
// floating points?
// check if fastio is causing the problem
// use feynman algorithm
