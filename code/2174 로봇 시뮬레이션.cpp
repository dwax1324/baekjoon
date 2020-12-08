#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<int, char>
#define pipii pair<int, pii>
#define pll pair<long, long>
#define ror(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
        cout << '\n';                            \
    }
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << ' ';
    err(++it, args...);
}

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
    구현    

<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void preprocess() {
}

int dxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
struct info {
    int x, y, num, dir;
};

int MAP[200][200];
info arr[200];
int MAPY, MAPX;
int coords, orders;
void print() {
    cout << '\n';
    ror(i, 1, MAPY + 1) {
        ror(j, 1, MAPX + 1) {
            cout << MAP[i][j] << " ";
        }
        cout << '\n';
    }
}
void solve() {
    cin >> MAPX >> MAPY;
    // error(MAPX, MAPY);
    cin >> coords >> orders;
    ror(i, 1, coords + 1) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        int d;
        switch (c) {
            case 'E': {
                d = 0;
                break;
            }
            case 'N': {
                d = 1;
                break;
            }
            case 'W': {
                d = 2;
                break;
            }
            case 'S': {
                d = 3;
                break;
            }
        }
        // cout << d;
        info kk;
        kk.dir = d;
        kk.num = i;
        kk.y = b;
        kk.x = a;
        MAP[b][a] = 1;
        arr[i] = kk;
    }

    ror(i, 0, orders) {
        int a, c;
        char b;
        cin >> a >> b >> c;
        // print();
        ror(j, 0, c) {
            switch (b) {
                case 'F': {
                    int y = arr[a].y;
                    int x = arr[a].x;
                    int ny = y + dxy[arr[a].dir][0];
                    int nx = x + dxy[arr[a].dir][1];
                    arr[a].y = ny;
                    arr[a].x = nx;
                    MAP[y][x] = 0;
                    if (ny < 1 || nx < 1 || ny >= MAPY + 1 || nx >= MAPX + 1) {
                        cout << "Robot " << a << " crashes into the wall\n";
                        return;
                    }
                    if (MAP[ny][nx] == 1) {
                        ror(k, 1, coords + 1) {
                            if (arr[k].num != a && ny == arr[k].y && nx == arr[k].x) {
                                cout << "Robot " << a << " crashes into robot " << k << '\n';
                                return;
                            }
                        }
                    }
                    MAP[ny][nx] = 1;
                    break;
                }
                case 'R': {
                    arr[a].dir = (arr[a].dir + 3) % 4;
                    break;
                }
                case 'L': {
                    arr[a].dir = (arr[a].dir + 1) % 4;
                    break;
                }
            }
        }
    }

    cout << "OK\n";
    return;
}
int main() {
    // fastio;
    debug;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    int t = 1;
    // cin >> t;  // ✨✨✨✨✨✨✨✨✨✨✨✨✨✨
    preprocess();
    ror(i, 1, t + 1) {
        // cout << "case #" << i << ": ";
        solve();
    }
}

// whats the point of this problem?
// are the number of the input correct?
// are there edge cases?
// how about overflow?
// data structres properly reset between test cases?
// floating points?
// check if fastio is causing the problem