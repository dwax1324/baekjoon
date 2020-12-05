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
    구현
    인구 이동

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}
int arr[51][51];
int cpy[51][51];
int vi[51][51];
int dx[5] = {1, -1, 0, 0};
int dy[5] = {0, 0, 1, -1};
int n, l, r;
bool flag;
int val;
queue<pii> go(int y, int x) {
    queue<pii> q, ret;
    vi[y][x] = true;
    q.push({y, x});
    int sum = arr[y][x];
    int cnt = 1;
    while (q.size()) {
        int curY = q.front().F;
        int curX = q.front().S;
        q.pop();
        fr(0, 4, i) {
            int ny = curY + dy[i];
            int nx = curX + dx[i];
            int diff = abs(arr[ny][nx] - arr[curY][curX]);
            if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
            if (vi[ny][nx]) continue;
            if (diff >= l && diff <= r) {
                flag = false;
                cnt++;
                sum += arr[ny][nx];
                q.push({ny, nx});
                vi[ny][nx] = true;
                ret.push({ny, nx});
            }
        }
    }
    val = sum / cnt;
    return ret;
}
int ans = 0;
void move() {
    fr(0, n, i) {
        fr(0, n, j) {
            cpy[i][j] = arr[i][j];
        }
    }
    fr(0, n, i) {
        fr(0, n, j) {
            if (!vi[i][j]) {
                val = 0;
                queue<pii> q = go(i, j);
                if (q.size()) {
                    cpy[i][j] = val;
                }
                while (q.size()) {
                    int curY = q.front().F;
                    int curX = q.front().S;
                    q.pop();
                    cpy[curY][curX] = val;
                }
            }
        }
    }
    fr(0, n, i) {
        fr(0, n, j) {
            arr[i][j] = cpy[i][j];
        }
    }
}

void solve() {
    cin >> n >> l >> r;

    fr(0, n, i) {
        fr(0, n, j) {
            cin >> arr[i][j];
        }
    }
    while (1) {
        flag = true;
        memset(vi, 0, sizeof(vi));
        move();
        ans++;
        // fr(0, n, i) {
        //     fr(0, n, j) {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        if (flag) break;
    }
    cout << ans - 1;
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
    // freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
}