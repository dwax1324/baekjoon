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
    pre+inorder to postorder
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int search(int arr[], int x, int n) {
    zz(0, i, n) {
        if (arr[i] == x) return i;
    }
    return -1;
}

void go(int pre[], int in[], int n) {
    int root = pre[0];
    int l = search(in, root, n);
    int r = n - 1 - l;
    // error(l);
    if (l > 0) {
        go(pre + 1, in, l);
    }
    if (l < n - 1) {
        go(pre + l + 1, in + l + 1, r);
    }

    cout << pre[0] << " ";
}
void solve() {
    int pre[1010];
    int in[1010];
    int n;
    cin >> n;
    memset(pre, 0, sizeof(pre));
    memset(in, 0, sizeof(in));
    zz(0, i, n) {
        cin >> pre[i];
    }
    zz(0, i, n) {
        cin >> in[i];
    }
    go(pre, in, n);
    cout << '\n';
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