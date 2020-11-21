#include <bits/stdc++.h>

using namespace std;

// 구현

// 복사배열을 만들고
// 50년뒤의 맵을 만들고
// 'X'의 좌표와 'Y'의 좌표를 따로 모아서 정렬후
// 최소 X ~ 최소 Y  + 최소 Y + 최대 Y만큼 출력

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    char arr[15][15];
    char cpy[15][15];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &arr[i][j]);
            cpy[i][j] = arr[i][j];
        }
    }
    int dxy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int ny = dxy[k][0] + i;
                int nx = dxy[k][1] + j;
                if (cpy[i][j] == 'X' && cpy[ny][nx] != 'X') cnt++;
            }
            if (cnt >= 3) arr[i][j] = '.';
        }
    }

    int x[50];
    int y[50];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'X') {
                y[cnt] = i;
                x[cnt] = j;
                cnt++;
            }
        }
    }

    for (int i = 0; i < cnt; i++) {
        // printf("%d%d ", x[i], x[i]);
    }
    sort(x, x + cnt);
    sort(y, y + cnt);

    for (int i = 0; i < cnt; i++) {
        // printf("%d%d ", x[i], y[i]);
    }

    for (int i = y[0]; i <= y[cnt - 1]; i++) {
        for (int j = x[0]; j <= x[cnt - 1]; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}