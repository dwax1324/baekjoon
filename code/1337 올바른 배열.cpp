#include <bits/stdc++.h>

// i번쨰 자리마다 5번 연속된 같은 숫자가 있는지 확인한다.
// 그중 가장 큰값
// 5- (MAX+1)

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());
    int MAX = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i + 1; j < n; j++) {
            for (int k = 1; k <= 4; k++) {
                if (v[j] == v[i] + k) cnt++;
                // if (v[j] > v[i] + k) break;
            }
        }
        MAX = max(cnt, MAX);
        // cout << cnt << " ";
    }
    cout << 5 - (MAX + 1);
}