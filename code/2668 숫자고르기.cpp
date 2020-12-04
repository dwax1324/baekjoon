#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
#define pipii pair<int, pii>
#define pll pair<long, long>
#define fr(num1, num2, i) for (int i = num1; i < num2; i++)
#define rfr(num1, num2, i) for (int i = num1 - 1; i >= num2; i--)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define F first
#define S second
using namespace std;
void fastio();
void debug();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    dfs
    
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
void preprocess() {
}

vector<int> v[101];
bool vi[101];

set<int> go(int idx, int k, set<int> s) {
    if (v[idx][0] == k) {
        s.insert(idx);
        s.insert(v[idx][0]);
        return s;
    }
    if (vi[v[idx][0]]) return {};
    vi[v[idx][0]] = true;
    s.insert(idx);
    s.insert(v[idx][0]);
    return go(v[idx][0], k, s);
}

void solve() {
    int n;
    cin >> n;
    fr(1, n + 1, i) {
        int a;
        cin >> a;
        v[i].push_back(a);
    }
    vector<int> ans;
    fr(1, n + 1, i) {
        memset(vi, 0, sizeof(vi));
        set<int> s = go(i, i, {});
        if (sz(s)) {
            for (auto x : s) {
                if (find(all(ans), x) == ans.end())
                    ans.push_back(x);
            }
        }
        // cout << '\n';
    }
    cout << sz(ans) << '\n';
    sort(all(ans));
    for (auto x : ans) cout << x << "\n";
}
int main() {
    fastio(), debug(), preprocess();
    int t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << t << ": ";
        solve();
    }
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
void fastio() {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
}

void debug() {
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
}