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
#define sz(x) ((int)(x).size())
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
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

vector<int> primes;
bool erra[100001];
void sieve() {
    for (int i = 2; i * i <= 100001; i++) {
        if (erra[i]) continue;
        for (int j = i * i; j <= 100001; j += i) {
            erra[j] = true;
        }
    }
}
void preprocess() {
    sieve();
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    queue<pii> q;
    q.push({n, 0});
    int dist[1000001];
    memset(dist, -1, sizeof(dist));
    dist[n] = 0;
    while (sz(q)) {
        int val = q.front().F;
        int cur = q.front().S;
        q.pop();
        if (val < 0) continue;
        if (val >= a && val <= b && erra[val] == 0) {
            cout << cur << '\n';
            return;
        }
        // error(val);
        ror(i, 0, 4) {
            if (i == 0) {
                int nx = val / 2;
                if (dist[nx] != -1) continue;
                dist[nx] = 1;
                q.push({nx, cur + 1});
            } else if (i == 1) {
                int nx = val / 3;
                if (dist[nx] != -1) continue;
                dist[nx] = 1;
                q.push({nx, cur + 1});
            } else if (i == 2) {
                int nx = val - 1;
                if (dist[nx] != -1) continue;
                dist[nx] = 1;
                q.push({nx, cur + 1});
            } else {
                int nx = val + 1;
                if (dist[nx] != -1) continue;
                dist[nx] = 1;
                q.push({nx, cur + 1});
            }
        }
    }
    cout << -1 << "\n";
}

int main() {
    fastio;
    debug;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    int t = 1;
    cin >> t;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    preprocess();
    ror(i, 0, t) {
        // cout << "case #" << t << ": ";
        solve();
    }
}