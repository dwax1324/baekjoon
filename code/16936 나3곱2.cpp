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
#define zz(begin, end, i) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
    완전탐색
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

bool vi[101];
int n;
vector<ll> v;

auto go(ll idx, ll cur, ll cnt, vector<ll> temp) {
    if (cnt == n - 1) {
        cout << v[idx] << " ";
        for (auto x : temp) cout << x << " ";
        exit(0);
        return;
    }
    // error(idx, cur, cnt);
    zz(0, n, i) {
        if (idx == i) continue;
        if (!vi[i] && v[cur] * 2 == v[i]) {
            vi[i] = true;
            temp.push_back(v[i]);
            go(idx, i, cnt + 1, temp);
            vi[i] = false;
        }
        if (!vi[i] && v[cur] == v[i] * 3) {
            vi[i] = true;
            temp.push_back(v[i]);
            go(idx, i, cnt + 1, temp);
            vi[i] = false;
        }
    }
}

auto solve() {
    cin >> n;
    v.resize(n);
    zz(0, n, i) {
        cin >> v[i];
    }
    zz(0, n, i) {
        go(i, i, 0, {});
    }
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