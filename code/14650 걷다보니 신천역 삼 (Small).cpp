#include <bits/stdc++.h>
//////////////////////////////////////////////
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define fr(i, num1, num2) for (int i = num1; i < num2; i++)
#define rfr(i, num1, num2) for (int i = num1 - 1; i >= num2; i--)
#define a first
#define b second
using namespace std;
void fastio();
void DEBUG();
///////////////////////////////////////////////
/*
    조합탐색

*/
///////////////////////////////////////////////

void preprocess() {
}

int cnt = 0;
void go(int depth, int n, string s) {
    if (depth == n) {
        if (stoi(s) == 0) return;
        if (s[0] == '0') return;
        if (stoi(s) % 3 == 0) {
            cnt++;
            // cout << stoi(s) << " ";
        }
        return;
    }
    go(depth + 1, n, s + '2');
    go(depth + 1, n, s + '0');
    go(depth + 1, n, s + '1');
}

void solve() {
    int n;
    cin >> n;
    go(0, n, "");
    cout << cnt;
}
int main() {
    fastio();
    preprocess();
    DEBUG();
    int t;
    t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << t << ": ";
        solve();
    }
}

///////////////////////////////////////////////
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void DEBUG() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}