#include <bits/stdc++.h>

// 부분합

using namespace std;

vector<int> v;
int main() {
    int n;
    cin >> n;
    v.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        v[i] = v[i - 1] + a;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        cout << v[b + 1] - v[a] << '\n';
    }
}