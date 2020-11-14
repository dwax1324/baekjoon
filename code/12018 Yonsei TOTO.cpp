#include <bits/stdc++.h>
using namespace std;

//  그리디
//  인원이 미달이어도 마일리지 1을 써야한다.
// 우선순위큐사용

int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> arr[101];
    int ans = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int p, l;
        cin >> p >> l;
        for (int j = 0; j < p; j++) {
            int a;
            cin >> a;
            arr[i].push(a);
        }
        if (p < l) {
            m -= 1;
            if (m >= 0) {
                ans++;
            }
            continue;
        }
        for (int j = 0; j < l - 1; j++) {
            arr[i].pop();
        }
        v.push_back(arr[i].top());
    }
    sort(v.begin(), v.end());
    // for (auto x : v) cout << x << ' ';
    for (int i = 0; i < v.size(); i++) {
        m -= v[i];
        if (m < 0) break;
        ans++;
    }
    cout << ans;
}