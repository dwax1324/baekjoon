#include <bits/stdc++.h>
using namespace std;

char arr[251][251];
bool vi[251][251];

// dfs/bfs
// 연습하기 좋은 문제

int cntV = 0, cntK = 0;
int n, m;
void dfs(int y, int x) {
    if (y < 0 || x < 0 || y >= n || x >= m) return;
    if (vi[y][x]) return;
    if (arr[y][x] == '#') return;
    if (arr[y][x] == 'v') cntV++;
    if (arr[y][x] == 'k') cntK++;
    vi[y][x] = true;

    dfs(y - 1, x);
    dfs(y + 1, x);
    dfs(y, x + 1);
    dfs(y, x - 1);
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            scanf(" %c", &arr[i][j]);
    }
    int ans[2] = {
        0,
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vi[i][j] && (arr[i][j] == 'v' || arr[i][j] == 'k')) {
                cntK = 0;
                cntV = 0;
                dfs(i, j);
                // printf("%d %d\n", cntK, cntV);
                if (cntK > cntV) {
                    ans[0] += cntK;
                } else {
                    ans[1] += cntV;
                }
            }
        }
    }

    printf("%d %d", ans[0], ans[1]);
}