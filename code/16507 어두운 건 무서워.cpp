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
    2D 구간합
    
*/
///////////////////////////////////////////////

void preprocess() {
}

int psum[1005][1005];
void solve() {
    int r, c, q;
    cin >> r >> c >> q;
    fr(i, 0, r) {
        fr(j, 0, c) {
            int a;
            cin >> a;
            psum[i + 1][j + 1] = psum[i + 1][j] + psum[i][j + 1] - psum[i][j] + a;
        }
    }
    // fr(i, 1, r + 1) {
    //     fr(j, 1, c + 1) {
    //         cout << psum[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    fr(i, 0, q) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int l = ((y2 - y1) + 1) * ((x2 - x1) + 1);
        int k = psum[y2][x2] - psum[y1 - 1][x2] - psum[y2][x1 - 1] + psum[y1 - 1][x1 - 1];
        cout << k / l << '\n';
    }
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