#include <bits/stdc++.h>

// 이분 탐색
// 정렬 잊지말자

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int m;
        cin >> m;
        vector<int> v2(n);
        for (int i = 0; i < m; i++) {
            cin >> v2[i];
        }

        for (int i = 0; i < m; i++) {
            cout << binary_search(v.begin(), v.end(), v2[i]) << '\n';
        }
    }
}