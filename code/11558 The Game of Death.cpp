#include <bits/stdc++.h>

// 그래프 탐색
// dfs/bfs를 이용해서 몇번째로 떨어져있는지 알 수 있다.

using namespace std;
int arr[10001];
int vi[10001];
int n;
int dfs(int x, int depth) {
    if (x == n) return 0;
    if (depth > n) return -1000000;
    int ret = dfs(arr[x], depth + 1);
    return ret + 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> arr[i];
        int x = dfs(1, 0);
        if (x < 0)
            cout << 0 << '\n';
        else
            cout << x << '\n';
    }
}