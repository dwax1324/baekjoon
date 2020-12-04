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
    구현 주사위 쌓기

    문제 자체는 쉬워보였으나
    인덱스가 굉장히 헷갈렸던문제

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/
void preprocess() {
}
int dx[] = {5, 3, 4, 1, 2, 0};
vector<vector<int>> v;
int n;
int sum;
// 숫자의 인덱스를 찾아주는 함수

int retIdx(int dice, int num) {
    int ret = 0;
    fr(0, 6, i) {
        if (v[dice][i] == num) return i;
    }
    return -1;
}

int calc(int dice, int idx) {
    int ret = 0;
    fr(0, 6, i) {
        if (i != idx && i != dx[idx]) {
            ret = max(ret, v[dice][i]);
        }
    }
    // cout << ret << " ";
    return ret;
}

void go(int dice, int side) {
    if (dice == n + 1) return;
    int idx = retIdx(dice, side);
    sum += calc(dice, idx);
    go(dice + 1, v[dice][dx[idx]]);
}

void solve() {
    cin >> n;
    v.resize(n + 1);
    fr(1, n + 1, i) {
        fr(0, 6, j) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    int ans = 0;
    fr(0, 6, i) {
        sum = calc(1, i);
        go(2, v[1][i]);
        ans = max(sum, ans);
    }
    cout << ans << '\n';
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