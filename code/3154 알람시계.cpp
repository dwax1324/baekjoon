#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
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
    구현
    
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}
vector<pipii> nums = {
    {1, {0, 0}},
    {2, {0, 1}},
    {3, {0, 2}},
    {4, {1, 0}},
    {5, {1, 1}},
    {6, {1, 2}},
    {7, {2, 0}},
    {8, {2, 1}},
    {9, {2, 2}},
    {0, {3, 1}},
};
int effort(vector<int> &v) {
    int y, x;
    fr(0, 10, i) {
        if (nums[i].F == v[0]) {
            y = nums[i].S.F;
            x = nums[i].S.S;
            break;
        }
    }
    int ret = 0;
    fr(1, 4, i) {
        fr(0, 10, j) {
            if (nums[j].F == v[i]) {
                ret += abs(y - nums[j].S.F) + abs(x - nums[j].S.S);
                x = nums[j].S.S;
                y = nums[j].S.F;
                break;
            }
        }
    }
    return ret;
}

vector<pair<int, string>> ans;
void go(int h, int m, int depth, vector<int> &v) {
    if (depth == 4) {
        int a = v[0] * 10 + v[1];
        int b = v[2] * 10 + v[3];
        // cout << a << " " << b << '\n';
        if (a % 24 == h && b % 60 == m) {
            string temp = "";
            for (auto x : v) {
                temp += to_string(x);
            }
            ans.pb({effort(v), temp});
        }
        return;
    }

    // int k = v.size() ? v.back() + 1 : 0;
    fr(0, 10, i) {
        v.push_back(i);
        go(h, m, depth + 1, v);
        v.pop_back();
    }
}

bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.F == b.F) return a.S < b.S;
    return a.F < b.F;
}

void solve() {
    string s;
    cin >> s;
    int a = stoi(s.substr(0, 2));
    int b = stoi(s.substr(3));
    vector<int> v;
    go(a, b, 0, v);
    // cout << ans.size();
    sort(ans.begin(), ans.end(), cmp);
    cout << ans[0].S.substr(0, 2) << ":" << ans[0].S.substr(2, 2);
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