#include <bits/stdc++.h>

// 단순구현
// bool곱 구현

using namespace std;

int main() {
    int n;
    cin >> n;
    bool v[301][301];
    bool v2[301][301];
    bool v3[301][301];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> v[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> v2[i][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int SUM = v[i][1] & v2[1][j];
            for (int k = 2; k <= n; k++) {
                SUM = SUM | (v[i][k] & v2[k][j]);
            }
            v3[i][j] = SUM;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (v3[i][j]) cnt++;
    }
    cout << cnt;
}