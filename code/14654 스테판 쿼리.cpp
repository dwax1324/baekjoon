#include <bits/stdc++.h>

// 단순구현
// 두개의 변수를 이용해 연승 횟수를 구한다

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

    int cnt1 = 0, cnt2 = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if ((a == 1 && v[i] == 3) || (a == 2 && v[i] == 1) || (a == 3 && v[i] == 2)) {
            cnt1++;
            cnt2 = 0;
        } else if ((v[i] == 1 && a == 3) || (v[i] == 2 && a == 1) || (v[i] == 3 && a == 2)) {
            cnt2++;
            cnt1 = 0;
        } else {
            if (cnt1) {
                cnt1 = 0;
                cnt2++;
            } else {
                cnt2 = 0;
                cnt1++;
            }
        }
        ans = max(cnt1, max(cnt2, ans));
    }
    cout << ans;
}