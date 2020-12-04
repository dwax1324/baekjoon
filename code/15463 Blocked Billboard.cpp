#include <bits/stdc++.h>
//////////////////////////////////////////////
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define fr(i, j, k) for (int i = j; i < k; i++)
#define rfr(i, j, k) for (int i = j - 1; i >= k; i--)
using namespace std;
void fastIO();
void fileIO();
///////////////////////////////////////////////
/*
    구현

    x가 y가 된다
    음수가 있으니 +1000해준다

    
*/
///////////////////////////////////////////////
void process() {
}
int arr[2001][2001];

void solve() {
    int x1, y1, x2, y2;
    int minY = 1 << 30, minX = 1 << 30, maxX = -1, maxY = -1;
    int temp;

    fr(i, 0, 3) {
        cin >> x1 >> y1 >> x2 >> y2;
        fr(j, x1, x2) {
            fr(k, y1, y2) {
                if (i == 2)
                    arr[j][k] = 2;
                else
                    arr[j][k] = 1;
            }
        }
    }
    int cnt = 0;
    fr(i, 0, 10) {
        fr(j, 0, 10) {
            cout << arr[i][j] << " ";
            if (arr[i][j] == 1) cnt++;
        }
        cout << '\n';
    }
    cout << cnt;
}

int main() {
    fastIO();
    fileIO();
    // process();
    int T;
    T = 1;
    // cin >> T;
    process();
    for (int i = 1; i <= T; i++) {
        // cout << "Case #" << T << ": ";
        solve();
        cout << '\n';
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