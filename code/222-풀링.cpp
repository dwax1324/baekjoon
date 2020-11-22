#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1025][1025];
int cpy[1025][1025];

// 구현
// dfs로 풀려다가 순서를 강제할 수 없어서
// 그냥 반복문으로 풀었다.
// 4칸씩 탐색하면서 진행하면된다.

void go(int y, int x) {
    int ny = 0,
        nx = 0;
    for (int i = 0; i < n; i += 2)
        for (int j = 0; j < n; j += 2) {
            // if (i + 2 >= n || j + 2 >= n) continue;
            int temp[5] = {arr[i][j], arr[i + 1][j], arr[i][j + 1], arr[i + 1][j + 1]};
            sort(temp, temp + 4);
            cpy[ny][nx] = temp[2];
            nx++;
            if (nx >= n / 2) {
                ny++;
                nx = 0;
            }
        }
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    while (n != 1) {
        go(0, 0);
        n /= 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = cpy[i][j];
            }
        }
    }

    printf("%d", arr[0][0]);
}