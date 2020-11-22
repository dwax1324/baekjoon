#include <bits/stdc++.h>

using namespace std;

// 최대 30C3  = 4060으로 완탐이 가능하다.
// 인덱스가 헷갈려서 실수좀했다.

int main() {
    int n, m;
    cin >> n >> m;
    int arr[31][31];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<int>> v;

    vector<int> temp;
    int MAX = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            for (int k = j + 1; k < m; k++) {
                int sum = 0;
                for (int z = 0; z < n; z++) {
                    sum += max({arr[z][i], arr[z][j], arr[z][k]});
                    // cout << arr[z][i] << arr[z][j] << arr[z][k] << '\n';
                }
                MAX = max(MAX, sum);
                // cout << sum << '\n';
            }
        }
        // v.push_back(temp);
    }
    cout << MAX;
}
