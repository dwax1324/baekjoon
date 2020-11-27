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
    dfs,bfs ,플로이드 워셜

    bfs로 풀었다.
    각 지점별로 가는 cost가 없으니 bfs를 써도 된다.
    문제가 좀 더 복잡한줄 알고 구조체쓰고 난리났었는데
    주변이 모두 편의점이니까 따로 거리의 나머지랑 남은 맥주를 저장안해도 됐다.
    한마디로 삽질했다.
    고로 코드가 좀 더럽다.

    
*/
///////////////////////////////////////////////
void process() {
}

typedef struct {
    int y;
    int x;
    int remain;
    int beer;
} info;

int n;
int sx, sy;
int lx, ly;
vector<pii> v;
map<pii, int> m;
bool bfs(int x, int y) {
    queue<info> q;
    m[{y, x}] = 1;
    info infor;
    infor.beer = 20;
    infor.remain = 0;
    infor.x = x;
    infor.y = y;
    q.push(infor);
    while (q.size()) {
        // int curBeer = q.front().beer;
        int curY = q.front().y;
        int curX = q.front().x;
        int remain = q.front().remain;
        q.pop();
        // cout << curY << " " << curX << '\n';
        if (curY == ly && curX == lx) {
            return true;
        }
        fr(i, 0, v.size()) {
            int Y = v[i].A;
            int X = v[i].B;
            // cout << Y << " " << X << '\n';
            int newBeer = (abs(Y - curY) + abs(X - curX) + remain);
            int newRemain = 0;
            if (newBeer > 1000) continue;
            if (m[{Y, X}] == 1) continue;
            m[{Y, X}] = 1;
            q.push({Y, X, newRemain, newBeer});
        }
    }
    return false;
}

void solve() {
    m = {};
    v = {};
    cin >> n;
    cin >> sx >> sy;
    fr(i, 0, n + 1) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }
    // for (auto x : v) cout << x.first << " ";
    // cout << '\n';
    // cout << v.size();
    lx = v[v.size() - 1].B;
    ly = v[v.size() - 1].A;

    if (bfs(sx, sy)) {
        cout << "happy\n";
    } else {
        cout << "sad\n";
    }
}
int main() {
    fastIO();
    int T;
    T = 1;
    cin >> T;
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