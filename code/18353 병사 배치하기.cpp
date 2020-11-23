#include <bits/stdc++.h>

using namespace std;

// dp lis 이분탐색
// 이분탐색으로 해결

// 입력을 받고 뒤에서부터 검사
// 전체길이 - lis의 길이

int main() {
    int n;
    cin >> n;
    vector<int> v;
    vector<int> v2 = {-(1 << 30)};

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (v2.back() < v[i]) {
            ans++;
            v2.push_back(v[i]);
        } else {
            auto it = lower_bound(v2.begin(), v2.end(), v[i]);
            *it = v[i];
        }
    }
    cout << n - ans;
}