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
void debuggggggggggg();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    이분탐색
    
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

vector<int> v;
int n, k;
bool check(int a) {
    ll cnt = 0;
    fr(0, sz(v), i) {
        if (v[i] < a) {
            cnt += (ll)(a - v[i]);
        } else {
            break;
        }
    }
    return cnt <= k;
}
void solve() {
    cin >> n >> k;
    v.resize(n);
    fr(0, n, i) {
        cin >> v[i];
    }
    sort(all(v));

    int l = 1;
    int r = 1e9;
    int ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
}
int main() {
    fastio();
    preprocess();
    debuggggggggggg();
    int t;
    t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << t << ": ";
        solve();
    }
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void debuggggggggggg() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}