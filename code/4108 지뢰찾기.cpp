#include <bits/stdc++.h>

// 단순구현
// 지뢰가 아닌 곳을 'A'로 초기화
// 지뢰 주변이면 1씩 더해준다.
// arr[i][j]-'A'하면서 출력

using namespace std;

int main() {
    int n, m;
    while (1) {
        cin >> n >> m;
        if (!n && !m) break;
        char arr[102][102];
        vector<pair<int, int>> dxy = {{1, 1},
                                      {-1, -1},
                                      {1, -1},
                                      {-1, 1},
                                      {1, 0},
                                      {0, 1},
                                      {-1, 0},
                                      {0, -1}};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> arr[i][j];
                if (arr[i][j] == '.') arr[i][j] = 'A';
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == '*') {
                    for (int k = 0; k < 8; k++) {
                        int ny = i + dxy[k].first;
                        int nx = j + dxy[k].second;
                        if (arr[ny][nx] == '*') continue;
                        arr[ny][nx] += 1;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (arr[i][j] == '*')
                    cout << '*';
                else
                    cout << arr[i][j] - 'A';
            }
            cout << '\n';
        }
    }
}