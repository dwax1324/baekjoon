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
    구현 로봇청소기

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

int arr[51][51];

const int dy[5] = {-1, 0, 1, 0};
const int dx[5] = {0, 1, 0, -1};

int n, m;
void print() {
    cout << '\n';
    fr(0, n, i) {
        fr(0, m, j) {
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
}

void solve() {
    cin >> n >> m;
    int r, c, d;
    cin >> r >> c >> d;
    fr(0, n, i) {
        fr(0, m, j) {
            cin >> arr[i][j];
        }
    }
    arr[r][c] = 2;
    int y = r;
    int x = c;
    int dir = d;
    int ans = 1;
    int ndir;
    int cnt = 0;
    while (1) {
        // if (cnt++ > 200) break;
        // print();
        bool flag = false;
        ndir = dir;
        fr(0, 4, i) {
            ndir = (ndir + 3) % 4;
            int ny = y + dy[ndir];
            int nx = x + dx[ndir];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || arr[ny][nx] != 0) continue;
            if (arr[ny][nx] == 0) {
                dir = ndir;
                arr[ny][nx] = 2;
                y = ny;
                x = nx;
                ans++;
                flag = true;
                break;
            }
        }
        if (!flag) {
            int ny = y + dy[(dir + 2) % 4];
            int nx = x + dx[(dir + 2) % 4];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == 1) break;
            y = ny;
            x = nx;
        }
    }
    cout << ans;
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