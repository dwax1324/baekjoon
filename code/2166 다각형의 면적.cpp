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
#define ror(begin, end, i) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
    shoelace formula

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

void solve() {
    int n;
    cin >> n;
    vector<pll> v;

    ror(0, n, i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    v.push_back({v[0].F, v[0].S});
    ll t1 = 0;
    ll t2 = 0;
    ror(0, sz(v) - 1, i) {
        t1 += v[i].F * v[i + 1].S;
        t2 += v[i].S * v[i + 1].F;
    }
    double a = (double)(abs(t1 - t2)) / (double)2;
    cout << fixed << setprecision(1) << a;
}
int main() {
    // fastio;
    debug;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    int t = 1;
    // cin >> t;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    preprocess();
    ror(1, t + 1, i) {
        // cout << "case #" << i << ": ";
        solve();
    }
}

// whats the point of this problem?
// are the number of the input correct?
// are there edge cases?
// how about overflow?
// data structres properly reset between test cases?
// floating points?
// check if fastio is causing the problem
// chill and think again