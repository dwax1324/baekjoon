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

bool isAllSame(vector<int>& v) {
    zz(0, i, sz(v) - 1) {
        if (v[i] != v[i + 1]) return false;
    }
    return true;
}

void next(vector<int>& v) {
    vector<int> temp(sz(v));
    zz(0, i, sz(v) - 1) {
        int k = v[i] / 2;
        v[i] /= 2;
        temp[i + 1] = k;
    }
    temp[0] = v.back() / 2;
    v.back() /= 2;
    zz(0, i, sz(v)) {
        v[i] += temp[i];
    }
}

void makeAllEven(vector<int>& v) {
    zz(0, i, sz(v)) {
        if (v[i] % 2 == 1) v[i]++;
    }
}
void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    zz(0, i, n) {
        cin >> v[i];
    }
    int cnt = 0;
    while (1) {
        makeAllEven(v);
        if (isAllSame(v)) {
            break;
        }
        next(v);
        cnt++;
    }
    cout << cnt << "\n";
}

auto main() -> int {
    fastio;
    debug;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    int t = 1;
    cin >> t;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
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
