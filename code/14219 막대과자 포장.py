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
    정수론 소수

*/
///////////////////////////////////////////////

bool vi[1299711];
vector<int> v;
void seive() {
    fr(i, 2, 1299710) {
        if (vi[i]) continue;
        vi[i] = true;
        v.push_back(i);
        for (int j = i * 2; j < 1299710; j += i) {
            vi[j] = true;
        }
    }
}
void preprocess() {
    seive();
}
void solve() {
    int a;
    cin >> a;
    int k = lower_bound(v.begin(), v.end(), a) - v.begin();
    if (v[k] == a)
        cout << 0 << '\n';
    else
        cout << v[k] - v[k - 1] << '\n';
}
int main() {
    fastIO();
    preprocess();
    fileIO();
    int T;
    T = 1;
    cin >> T;
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
