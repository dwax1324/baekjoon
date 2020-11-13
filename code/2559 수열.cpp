#include <bits/stdc++.h>

// 누적합

using namespace std;
vector<int> v(100000 + 1);

int main() {
    int n, k;
    cin >> n >> k;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        sum += a;
        v[i] = sum;
    }

    // for (auto x : v) cout << x << " ";

    int MAX = v[k];
    for (int i = 1; i <= n; i++) {
        int l = i;
        int r = i + k;
        if (r > n) break;
        // cout << v[r] << " " << v[l] << '\n';
        MAX = max(MAX, v[r] - v[l]);
    }
    cout << MAX;
}