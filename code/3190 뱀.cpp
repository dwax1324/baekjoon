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

    뱀~
    케이스워크가 좀 필요하다

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

int arr[101][101];
int n, k, l;
deque<pii> dq;

bool moveRight() {
    bool ret = false;
    int ny = dq.back().F;
    int nx = dq.back().S + 1;
    if (nx < 1 || nx >= n + 1) {
        ret = true;
    }
    if (arr[ny][nx] == 1) {
        ret = true;
    }
    if (arr[ny][nx] == 2) {
        arr[ny][nx] = 1;
        dq.push_back({ny, nx});
    } else {
        arr[ny][nx] = 1;
        dq.push_back({ny, nx});
        arr[dq.front().F][dq.front().S] = 0;
        dq.pop_front();
    }
    return ret;
}

bool moveLeft() {
    bool ret = false;
    int ny = dq.back().F;
    int nx = dq.back().S - 1;
    if (nx < 1 || nx >= n + 1) {
        ret = true;
    }
    if (arr[ny][nx] == 1) {
        ret = true;
    }
    if (arr[ny][nx] == 2) {
        dq.push_back({ny, nx});
    } else {
        arr[ny][nx] = 1;
        dq.push_back({ny, nx});
        arr[dq.front().F][dq.front().S] = 0;
        dq.pop_front();
    }
    return ret;
}
bool moveUp() {
    bool ret = false;
    int ny = dq.back().F - 1;
    int nx = dq.back().S;
    if (ny < 1 || ny >= n + 1) {
        ret = true;
    }
    if (arr[ny][nx] == 1) {
        ret = true;
    }
    if (arr[ny][nx] == 2) {
        dq.push_back({ny, nx});
    } else {
        arr[ny][nx] = 1;
        dq.push_back({ny, nx});
        arr[dq.front().F][dq.front().S] = 0;
        dq.pop_front();
    }
    return ret;
}
bool moveDown() {
    bool ret = false;
    int ny = dq.back().F + 1;
    int nx = dq.back().S;
    if (ny < 1 || ny >= n + 1) {
        ret = true;
    }
    if (arr[ny][nx] == 1) {
        ret = true;
    }
    if (arr[ny][nx] == 2) {
        dq.push_back({ny, nx});
    } else {
        arr[ny][nx] = 1;
        dq.push_back({ny, nx});
        arr[dq.front().F][dq.front().S] = 0;
        dq.pop_front();
    }
    return ret;
}
void solve() {
    cin >> n >> k;
    fr(0, k, i) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 2;
    }
    arr[1][1] = 1;

    cin >> l;
    dq.pb({1, 1});
    priority_queue<pic, vector<pic>, greater<pic>> pq;
    fr(0, l, i) {
        int a;
        char b;
        cin >> a >> b;
        pq.push({a, b});
    }

    int ans = 0;
    int dir = 1;
    while (1) {
        ans++;
        // fr(0, n, i) {
        //     fr(0, n, j) {
        //         cout << arr[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        // cout << '\n';
        if (dir == 1) {
            if (moveRight()) break;
        } else if (dir == 3) {
            if (moveLeft()) break;
        } else if (dir == 2) {
            if (moveUp()) break;
        } else {
            if (moveDown()) break;
        }
        if (ans == pq.top().first) {
            if (pq.top().second == 'L') {
                dir++;
                if (dir == 5) dir = 1;
            } else {
                dir--;
                if (dir == 0) dir = 4;
            }
            pq.pop();
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