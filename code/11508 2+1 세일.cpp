#include <bits/stdc++.h>
using namespace std;

// 그리디

// 역순정렬후 3개씩 묶는다

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        tot += v[i];
    }
    sort(v.begin() + 1, v.begin() + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0) tot -= v[i];
    }
    cout << tot;
}