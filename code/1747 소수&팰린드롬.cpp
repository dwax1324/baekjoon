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
    정수론 체 펠린드롬
    

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

bool vi[1003002];
vector<int> seive() {
    vector<int> ret;
    int sq = sqrt(1003002);
    for (int i = 2; i <= sq; i++) {
        if (vi[i]) continue;
        for (int j = i * i; j <= 1003002; j += i) {
            vi[j] = true;
        }
    }

    fr(2, 1003002, i) {
        if (!vi[i]) {
            ret.push_back(i);
        }
    }
    return ret;
}

bool check(int a) {
    string b = to_string(a);
    string c = b;
    reverse(b.begin(), b.end());
    return b == c;
}

void solve() {
    vector<int> v = seive();
    int n;
    cin >> n;

    // fr(0, 10, i) {
    //     cout << v[i] << " ";
    // }
    fr(0, v.size(), i) {
        if (v[i] >= n && check(v[i])) {
            cout << v[i];
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