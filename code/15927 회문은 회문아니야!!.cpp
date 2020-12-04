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
    애드혹 : 
    정형화된 방법이 아닌 
    아이디어가 떠올라야함


<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
void preprocess() {
}

bool isPalin(string& s) {
    fr(0, sz(s), i) {
        if (s[i] != s[sz(s) - i - 1]) return false;
    }
    return true;
}

bool isOneChar(string& s) {
    fr(0, sz(s) - 1, i) {
        if (s[i] != s[i + 1]) return false;
    }
    return true;
}

void solve() {
    string s;
    cin >> s;
    if (isPalin(s)) {
        if (isOneChar(s))
            cout << -1;
        else
            cout << sz(s) - 1;
    } else {
        cout << sz(s);
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