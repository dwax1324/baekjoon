#include <bits/stdc++.h>
using namespace std;

int arr[4][100001];

// 구간합

// 구간합3개구하기

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        if (a == 1) {
            arr[1][i] = 1;
        } else if (a == 2) {
            arr[2][i] = 1;
        } else {
            arr[3][i] = 1;
        }
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            arr[i][j] += arr[i][j - 1];
        }
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << arr[1][b] - arr[1][a - 1] << ' ';
        cout << arr[2][b] - arr[2][a - 1] << ' ';
        cout << arr[3][b] - arr[3][a - 1];
        cout << '\n';
    }
}