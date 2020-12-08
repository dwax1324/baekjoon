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
    구현
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int day(int h, int m, int d) {
    int ret = 0;
    ret = d % 60 ? d / 60 + 1 : d / 60;
    return ret * 1000;
}

int night(int h, int m, int d) {
    int pivot = m + 1;
    int ret = 0;
    while (1) {
        if (d <= 0) break;
        if (h >= 22 || h < 8) {
            int t = 0;
            while (1) {
                if (h == 8 && m == 0) break;
                t++;
                m++;
                if (m == 60) {
                    m = 0;
                    h++;
                }
                if (h == 24) {
                    h = 0;
                }
            }
            d -= t;
            ret += 5000;
            pivot = 1;
        } else {
            m++;
            d--;
            if (m == pivot) {
                ret += 1000;
            }
            if (m == 60) {
                m = 0;
                h++;
            }
            if (h == 24) {
                h = 0;
            }
        }
    }
    return ret;
}

auto solve() {
    string s;
    int d;
    cin >> s >> d;
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    cout << min(day(h, m, d), night(h, m, d)) << '\n';
    // error(day(h, m, d), night(h, m, d));
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