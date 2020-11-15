#include <bits/stdc++.h>
using namespace std;

// 구현

// 1018 체스판 다시 칠하기랑 비슷한문제
//https://www.acmicpc.net/problem/1018

int main() {
    int n, m;
    cin >> n >> m;
    int arr[41][41];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int t;
    cin >> t;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i + 3 > n) break;
            if (j + 3 > m) break;
            vector<int> temp;
            for (int k = i; k < i + 3; k++) {
                for (int z = j; z < j + 3; z++) {
                    temp.push_back(arr[k][z]);
                }
            }
            sort(temp.begin(), temp.end());
            // for (auto x : temp) {
            //     cout << x << " ";
            // }
            // cout << '\n';
            if (temp[4] >= t) cnt++;
        }
    }
    cout << cnt;
}