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
    에라토스테네스 응용

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
int vi[5000001];

auto go(int a) {
    if (a == 1) {
        cout << 1;
        return;
    }
    while (a > 1) {
        cout << vi[a] << " ";
        // error(a, vi[a]);
        a /= vi[a];
    }
}

auto solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        // error(a, vi[a]);
        go(a);
        cout << '\n';
    }
}
void sieve() {
    vi[0] = vi[1] = -1;
    for (int i = 2; i <= 5000000; i++) {
        vi[i] = i;
    }
    for (int i = 2; i * i <= 5000000; i++) {
        if (vi[i] == i)
            for (int j = i * i; j <= 5000000; j += i) {
                if (vi[j] == j) {
                    vi[j] = i;
                }
            }
    }
}

auto main() -> int {
    fastio;
    debug;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    int t = 1;
    // cin >> t;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    sieve();
    ror(1, t + 1, i) {
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
// chill and think again
// use feynman algorithm