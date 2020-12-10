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
    완탐
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int n, m;
vector<int> v;

bool check(int a) {
    int vi[10];
    memset(vi, 0, sizeof(vi));
    int cnt = 0;
    while (a) {
        cnt++;
        vi[a % 10]++;
        a /= 10;
    }
    if (cnt < n) {
        ff(0, i, n - cnt) {
            vi[0]++;
        }
    }
    int ret = 0;
    int vi2[10];
    memset(vi2, 0, sizeof(vi2));
    ff(0, i, sz(v)) {
        if (vi2[v[i]]) continue;
        if (vi[v[i]]) ret++;
        vi2[v[i]]++;
    }
    return ret == m;
}

void solve() {
    cin >> n >> m;
    ff(0, i, m) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    int e = 1;
    ff(0, i, n) {
        e *= 10;
    }
    int cnt = 0;
    ff(0, i, e) {
        if (check(i)) cnt++;
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
