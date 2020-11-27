#include <bits/stdc++.h>
//////////////////////////////////////////////
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define fr(i, j, k) for (int i = j; i < k; i++)
#define rfr(i, j, k) for (int i = j - 1; i >= k; i--)
#define A first
#define B second
using namespace std;
void fastIO();
void fileIO();
///////////////////////////////////////////////
/*
    완전탐색
    자릿수로 접근해야한다
    1~10억보다 4,7인 숫자의 갯수를 세는게 더 빠르다.

*/
///////////////////////////////////////////////
void process() {
}

vector<int> v;

void go(int depth, int b, string s) {
    if (depth == b) {
        v.push_back(stoi(s));
        return;
    }
    go(depth + 1, b, s + '4');
    go(depth + 1, b, s + '7');
}

void solve() {
    int a, b;
    cin >> a >> b;
    fr(i, 1, 10) {
        go(0, i, "");
    }
    int cnt = 0;
    for (auto x : v) {
        if (x <= b && x >= a) {
            cnt++;
        }
    }
    cout << cnt;
}
int main() {
    fastIO();
    int T;
    T = 1;
    // cin >> T;
    // fileIO();
    process();
    for (int i = 1; i <= T; i++) {
        // cout << "Case #" << T << ": ";
        solve();
    }
}

///////////////////////////////////////////////
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}