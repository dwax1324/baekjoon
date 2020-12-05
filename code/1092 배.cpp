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
#define pb push_back
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
    
    둘 다 역순정렬후
    크레인에서 3개씩 빼낸다.
    
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
void preprocess() {
}

void solve() {
    int n;
    cin >> n;
    vector<int> v1, v2;
    ror(0, n, i) {
        int a;
        cin >> a;
        v1.push_back(a);
    }
    int b;
    cin >> b;
    ror(0, b, i) {
        int a;
        cin >> a;
        v2.push_back(a);
    }
    sort(rall(v1));
    sort(rall(v2));

    if (v2[0] > v1[0]) {
        cout << -1;
        exit(0);
    }
    int cnt = 0;
    while (sz(v2)) {
        cnt++;
        ror(0, n, i) {
            for (auto it = v2.begin(); it isnot v2.end();) {
                if (*it <= v1[i]) {
                    v2.erase(it);
                    break;
                } else {
                    ++it;
                }
            }
        }
    }
    cout << cnt;
}

int main() {
    fastio;
    preprocess();
    debug;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    int t = 1;
    // cin >> t;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    ror(0, t, i) {
        // cout << "case #" << t << ": ";
        solve();
    }
}