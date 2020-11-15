#include <bits/stdc++.h>

using namespace std;

// 구간합

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> pv(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> pv[i];
    }

    sort(pv.begin() + 1, pv.begin() + n + 1);

    for (int i = 1; i <= n; i++) {
        pv[i] += pv[i - 1];
    }
    // for (auto x : pv) cout << x << " ";

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << pv[b] - pv[a - 1] << '\n';
    }
}