#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<int, char>
#define pipii pair<int, pii>
#define pll pair<long, long>
#define ror(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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
    dfs/bfs
    가장 큰값 뺴주면됨.
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}
const int maxN = 100001;
vector<pii> v[maxN];
int vi[maxN];
bool rvi[maxN];
int n, s, e;
struct info {
    int cur, val, max;
};
void solve() {
    cin >> n >> s >> e;
    ror(i, 0, n - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    queue<info> q;
    q.push({s, 0, 0});
    rvi[s] = true;
    while (q.size()) {
        int cur = q.front().cur;
        int val = q.front().val;
        int MAX = q.front().max;
        q.pop();
        if (cur == e) {
            cout << val - MAX;
            break;
        }
        ror(i, 0, v[cur].size()) {
            int next = v[cur][i].F;
            int path = v[cur][i].S;
            if (!rvi[next]) {
                q.push({next, val + path, max(MAX, path)});
                rvi[next] = true;
            }
        }
    }
}
int main() {
    fastio;
    debug;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    int t = 1;
    // cin >> t;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    preprocess();
    ror(i, 0, t) {
        // cout << "case #" << t << ": ";
        solve();
    }
}