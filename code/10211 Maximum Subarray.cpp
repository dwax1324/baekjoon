#include <bits/stdc++.h>

// 부분합
// 최솟값은 0이 아니다!

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> psum(n + 1);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            psum[i + 1] = psum[i] + a;
        }
        int ans = -(1 << 30);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans = max(ans, psum[j] - psum[i]);
            }
        }

        cout << ans << '\n';
    }
}