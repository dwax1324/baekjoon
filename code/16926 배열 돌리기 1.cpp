#include <bits/stdc++.h>

// 복사배열을 만들어 풀었다.
// 반복문을 써서 임시값을 저장해주고 하면 복사배열 필요없을듯
// 더 좋은 풀이가 있다.
// 일단 마음가는대로 구현해봤다.

using namespace std;
int arr[301][301];
int cpy[301][301];
int n, m, r;

void goDown(int y, int x, int k) {
    if (y == k) return;
    arr[y + 1][x] = cpy[y][x];
    goDown(y + 1, x, k);
}
void goRight(int y, int x, int k) {
    if (x == k) return;
    arr[y][x + 1] = cpy[y][x];
    goRight(y, x + 1, k);
}
void goUp(int y, int x, int k) {
    if (y == k) return;
    arr[y - 1][x] = cpy[y][x];
    goUp(y - 1, x, k);
}

void goLeft(int y, int x, int k) {
    if (x == k) return;
    arr[y][x - 1] = cpy[y][x];
    goLeft(y, x - 1, k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            cpy[i][j] = arr[i][j];
        }
    }

    int MIN = min(n, m) / 2;

    for (int k = 0; k < r; k++) {
        for (int i = 0; i < MIN; i++) {
            goDown(i, i, n - i - 1);
            goRight(n - i - 1, i, m - i - 1);
            goUp(n - i - 1, m - i - 1, i);
            goLeft(i, m - i - 1, i);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cpy[i][j] = arr[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}