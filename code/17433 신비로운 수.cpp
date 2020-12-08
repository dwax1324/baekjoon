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
일단 먼저 신비로운 수가 무한으로 발산하는 케이스를 찾아야한다. 이는 주어진 n개의 수가 모두 신비의 수가 뭐든지간에 같은 나머지를 가져야하므로 주어진 n개의 수가 모두 같을때가 된다. 
벡터에 abs(a[i+1]-a[i])를 해주며 각 요소간의 차를 넣는다.
정렬을 해주고 전체의 최대공약수
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void solve() {
    int n;
    cin >> n;
    int a = 0;
    vector<int> v;
    zz(0, n, i) {
        int b;
        cin >> b;
        if (!i)
            a = b;
        else {
            if (abs(a - b)) {
                v.push_back(abs(a - b));
                a = b;
            }
        }
    }
    if (!sz(v)) {
        cout << "INFINITY\n";
        return;
    }
    sort(all(v));
    a = v[0];
    zz(1, sz(v), i) {
        a = gcd(a, v[i]);
    }
    cout << a << '\n';
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