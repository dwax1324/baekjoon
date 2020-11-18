#include <bits/stdc++.h>

using namespace std;

// 구현 그리디

// 사람이 앉는 자리면 8방향으로 탐색하여
// 사람이 없으면 그 자리에 있는 값을 1씩올린다
// 사람이 있으면 정답에 1을 올린다.
// 악수는 항상 두명이 하니까 정답에 /2해주면 된다.
// 배열에 저장된 숫자의 최댓값+ 정답/2해주면 된다.

int main() {
    int n, m;
    cin >> n >> m;
    int arr[51][51];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char a;
            cin >> a;
            if (a == 'o') {
                arr[i][j] = -1;
            } else {
                arr[i][j] = 0;
            }
        }
    }

    int dxy[8][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    int cnt = 0;
    int MAX = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == -1) {
                for (int z = 0; z < 8; z++) {
                    int ny = i + dxy[z][0];
                    int nx = j + dxy[z][1];
                    if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                    if (arr[ny][nx] == -1) {
                        cnt++;
                    } else {
                        arr[ny][nx]++;
                        MAX = max(arr[ny][nx], MAX);
                    }
                }
            }
        }
    }

    cout << MAX + cnt / 2;
}