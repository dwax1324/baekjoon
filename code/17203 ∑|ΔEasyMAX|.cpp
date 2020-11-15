#include <bits/stdc++.h>

using namespace std;

// 구간합
// 배열 하나 더 써서 변화량을 저장하고
// 구간합을 구한 후 쿼리에 답한다.

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> pv;
    for (int i = 1; i <= n; i++) {
        int a;
        int prev;
        cin >> a;
        if (i == 1)
            pv.push_back(0);
        else
            pv.push_back(abs(prev - a));
        prev = a;
    }
    pv[0] = 0;
    for (int i = 1; i < pv.size(); i++) {
        pv[i] += pv[i - 1];
    }

    // for (auto x : pv) {
    //     cout << x << " ";
    // }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << pv[b - 1] - pv[a - 1] << '\n';
    }
}