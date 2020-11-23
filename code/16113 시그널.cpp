#include <bits/stdc++.h>

using namespace std;

// 구현

int check[5][3];
char arr[5][20001];
int vi[5][20001];
int n, m;
void go(int y, int x, int X) {
    if (y >= n || x >= m || y < 0 || x < 0) return;
    if (vi[y][x]) return;
    if (arr[y][x] != '#') return;
    vi[y][x] = true;
    check[y][x - X] = 1;
    go(y, x + 1, X);
    go(y + 1, x, X);
    go(y - 1, x, X);
    go(y, x - 1, X);
}

int nums[10][5][3] = {
    {{1, 1, 1}, {1, 0, 1}, {1, 0, 1}, {1, 0, 1}, {1, 1, 1}},
    {{1, 0, 0}, {1, 0, 0}, {1, 0, 0}, {1, 0, 0}, {1, 0, 0}},
    {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {1, 0, 0}, {1, 1, 1}},
    {{1, 1, 1}, {0, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}},
    {{1, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {0, 0, 1}},
    {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}},
    {{1, 1, 1}, {1, 0, 0}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
    {{1, 1, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}, {0, 0, 1}},
    {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
    {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {0, 0, 1}, {1, 1, 1}},
};
int whatIsThisNumberMotherFather() {
    int ret = 0;
    for (int k = 0; k < 10; k++) {
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                if (nums[k][i][j] == check[i][j]) cnt++;
            }
        }
        if (cnt == 15) {
            ret = k;
            break;
        }
    }
    return ret;
}

int main() {
    int z;
    cin >> z;
    n = 5;
    m = z / 5;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << arr[i][j];
    //     }
    //     cout << '\n';
    // }
    memset(vi, 0, sizeof(vi));
    for (int i = 0; i < m; i++) {
        if (arr[0][i] != '.' && !vi[0][i]) {
            memset(check, 0, sizeof(check));
            go(0, i, i);
            // cout << '\n';
            // for (int j = 0; j < 5; j++) {
            //     for (int k = 0; k < 3; k++) {
            //         cout << check[j][k];
            //     }
            //     cout << '\n';
            // }
            cout << whatIsThisNumberMotherFather();
        }
    }
}