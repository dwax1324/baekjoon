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
    수학 완전탐색
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

bool arr[1048577];
int n;
vector<int> nums;
void go(int depth, vector<int> &v, int sum) {
    if (depth == 0) {
        // if (sum > 230) return;
        // cout << sum << '\n';
        arr[sum] = true;
        return;
    }

    int smallest = sz(v) ? v.back() + 1 : 0;

    fr(smallest, n, i) {
        if (sum + nums[i] > 1048576) continue;
        // if (arr[sum + nums[i]]) continue;
        v.push_back(i);
        go(depth - 1, v, sum + nums[i]);
        v.pop_back();
    }
}

void solve() {
    cin >> n;
    nums.resize(n);
    fr(0, n, i) {
        cin >> nums[i];
    }
    sort(all(nums));
    fr(1, n + 1, i) {
        vector<int> v = {};
        go(i, v, 0);
    }
    fr(1, 1048576 + 1, i) {
        if (!arr[i]) {
            cout << i;
            break;
        }
    }
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