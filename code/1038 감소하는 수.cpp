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
    완전 탐색
    입력이 백만까진건 훼이크다..!

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}
int n;
vector<string> v;
void go(int depth, string s, int r, vector<int> picked) {
    if (depth == r) {
        // cout << s << '\n';
        v.push_back(s);
        return;
    }
    int k = picked.size() ? picked.back() + 1 : 0;

    fr(k, 10, i) {
        string ti = to_string(i);
        string z = s + ti;
        string z2 = z;
        sort(rall(z2));
        bool flag = false;
        fr(0, sz(s), j) if (s[j] == (char)(i + '0')) {
            flag = true;
            break;
        }
        if (flag) continue;
        if (z != z2) continue;
        go(depth + 1, z, r, picked);
    }
}

void solve() {
    cin >> n;
    int i = 1;
    int cnt = 0;
    while (1) {
        if (cnt++ > 20) break;
        go(0, "", i++, {});
    }
    // cout << sz(v);

    if (n >= sz(v))
        cout << -1;
    else
        cout << v[n];
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