#include <bits/stdc++.h>

using namespace std;

// 구간합
// 그리디

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> pv(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        long long a;
        cin >> a;
        pv[i] = pv[i - 1] + a;
    }

    long long ans = 0;
    for (int i = 0; i + m <= n; i++) {
        ans = max(pv[i + m] - pv[i], ans);
    }
    cout << ans;
}