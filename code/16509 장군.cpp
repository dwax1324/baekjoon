#include <bits/stdc++.h>
//////////////////////////////////////////////
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define fr(num1, num2, i) for (int i = num1; i < num2; i++)
#define rfr(num1, num2, i) for (int i = num1 - 1; i >= num2; i--)
#define F first
#define S second
using namespace std;
void fastio();
void DEBUG();
///////////////////////////////////////////////
/*
    bfs
    하드코딩했다..
    이 방법 말고도 bfs단계를 3번씩 나눠서 해도 될거같다.

*/
///////////////////////////////////////////////

void preprocess() {
}
int dxy[8][2] = {{3, -2}, {3, 2}, {-3, -2}, {-3, 2}, {2, 3}, {-2, 3}, {2, -3}, {-2, -3}};

int ty, tx;
bool notPassed(int a, int y, int x) {
    //y +3
    if (a == 0) {
        if (x == tx && y + 1 == ty) return true;
        if (x - 1 == tx && y + 2 == ty) return true;
    } else if (a == 1) {
        if (x == tx && y + 1 == ty) return true;
        if (x + 1 == tx && y + 2 == ty) return true;
        //y -3
    } else if (a == 2) {
        if (x == tx && y - 1 == ty) return true;
        if (x - 1 == tx && y - 2 == ty) return true;
    } else if (a == 3) {
        if (x == tx && y - 1 == ty) return true;
        if (x + 1 == tx && y - 2 == ty) return true;
        // x +3
    } else if (a == 4) {
        if (x + 1 == tx && y == ty) return true;
        if (x + 2 == tx && y + 1 == ty) return true;
    } else if (a == 5) {
        if (x + 1 == tx && y == ty) return true;
        if (x + 2 == tx && y - 1 == ty) return true;
        // x-3
    } else if (a == 6) {
        if (x - 1 == tx && y == ty) return true;
        if (x - 2 == tx && y + 1 == ty) return true;
    } else if (a == 7) {
        if (x - 1 == tx && y == ty) return true;
        if (x - 2 == tx && y - 1 == ty) return true;
    }
    return false;
}
bool vi[11][11];
void solve() {
    int n, m;
    cin >> n >> m;
    cin >> ty >> tx;

    queue<ppii> q;
    q.push({0, {n, m}});
    vi[n][m] = true;
    int cnt = 0;
    while (q.size()) {
        int curX = q.front().S.S;
        int curY = q.front().S.F;
        int mvs = q.front().F;
        q.pop();

        if (curY == ty && curX == tx) {
            cout << mvs;
            exit(0);
        }
        fr(0, 8, i) {
            int ny = curY + dxy[i][0];
            int nx = curX + dxy[i][1];
            if (ny < 0 || nx < 0 || ny >= 10 || nx >= 9) continue;
            if (notPassed(i, curY, curX)) continue;
            if (vi[ny][nx]) continue;
            vi[ny][nx] = true;
            q.push({mvs + 1, {ny, nx}});
        }
    }

    cout << -1;
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