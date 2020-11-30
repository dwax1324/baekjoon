#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define pll pair<long, long>
#define fr(num1, num2, i) for (int i = num1; i < num2; i++)
#define rfr(num1, num2, i) for (int i = num1 - 1; i >= num2; i--)
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
using namespace std;
void fastio();
void debug();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
   bfs/dfs 
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

vector<int> arr[50001];
bool vi[50001];
int sum = 0;
vector<int> v;
void go(int a) {
    if (vi[a]) return;
    vi[a] = true;
    sum += v[a];
    fr(0, sz(arr[a]), i) {
        if (!vi[arr[a][i]]) {
            go(arr[a][i]);
        }
    }
}

void solve() {
    int n, m;
    v.resize(n);
    cin >> n >> m;
    fr(0, n, i) {
        cin >> v[i];
    }
    fr(0, m, i) {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    bool flag = false;
    fr(0, n, i) {
        if (!vi[i]) {
            sum = 0;
            go(i);
            if (sum != 0) flag = true;
        }
    }
    if (flag)
        cout << "IMPOSSIBLE";
    else
        cout << "POSSIBLE";
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