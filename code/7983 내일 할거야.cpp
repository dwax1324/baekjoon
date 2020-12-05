#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
#define pipii pair<int, pii>
#define pll pair<long, long>
#define ror(begin, end, i) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define is ==
#define isnot !=
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
    그리디
    블럭쌓아가듯이 맨뒤에서부터 
    변수 cur을 끝나는시간 - 걸리는시간 로 초기화 시키고
    만약 cur이 다음 끝나는 시간보다 일찍 끝나면
    cur을 다음시간의 끝나는 시간으로 초기화시키고
    아니면 시간이 연장됐기 때문에 cur을 cur+ 걸리는 시간으로 초기화한다.
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
void preprocess() {
}
void solve() {
    int n;
    cin >> n;
    vector<pii> v(n);
    ror(0, n, i) {
        cin >> v[i].F >> v[i].S;
    }
    sort(all(v), [](pii a, pii b) {
        if (a.S == b.S) return a.F > b.F;
        return a.S < b.S;
    });

    int cur = v[n - 1].S - v[n - 1].F;
    ror(n - 1, 0, i) {
        if (cur > v[i].S) {
            cur = v[i].S - v[i].F;
        } else {
            cur = cur - v[i].F;
        }
    }

    cout << cur;
}

int main() {
    fastio;
    debug;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    int t = 1;
    // cin >> t;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    preprocess();
    ror(0, t, i) {
        // cout << "case #" << t << ": ";
        solve();
    }
}