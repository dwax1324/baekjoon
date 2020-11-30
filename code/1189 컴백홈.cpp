#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define ppii pair<int, pii>
#define pll pair<long, long>
#define fr(num1, num2, i) for (int i = num1; i < num2; i++)
#define rfr(num1, num2, i) for (int i = num1 - 1; i >= num2; i--)
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
using namespace std;
void fastio();
void 쩜씸나깔껐깥아();
/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    백트래킹
    완전탐색

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}
int n, m, k;
bool vi[10][10];
char arr[10][10];
int cnt = 0;

int dxy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void go(int y, int x, int depth) {
    if (y < 1 || x < 1 || y >= n + 1 || x >= m + 1) return;
    if (arr[y][x] == 'T') return;
    if (y == 1 && x == m) {
        if (depth == k) cnt++;
        // cout << depth;
        return;
    }
    int ret;
    vi[y][x] = true;
    fr(0, 4, i) {
        int ny = y + dxy[i][0];
        int nx = x + dxy[i][1];
        if (vi[ny][nx]) continue;
        vi[ny][nx] = true;
        go(ny, nx, depth + 1);
        vi[ny][nx] = false;
    }
    // return ret;
}

void solve() {
    cin >> n >> m >> k;
    fr(1, n + 1, i) {
        fr(1, m + 1, j) {
            cin >> arr[i][j];
        }
    }
    // fr(1, n + 1, i) {
    //     fr(1, m + 1, j) {
    //         cout << arr[i][j];
    //     }
    //     cout << '\n';
    // }
    go(n, 1, 1);
    cout << cnt;
}

int main() {
    fastio();
    preprocess();
    쩜씸나깔껐깥아();
    int t;
    t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << t << ": ";
        solve();
    }
}

//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//\\//
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void 쩜씸나깔껐깥아() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}