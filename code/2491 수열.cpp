#include <bits/stdc++.h>

// dp? 구현
// 문제를 제대로 안읽고  lis로 풀다가 틀렸다.
// dp가 아닌거같은데 분류에 그렇게 되어있다.
// 그냥 연속증가,감소구간 체킹해주면된다.

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int ans = 0, ans2 = 0;
    int cnt = 1, cnt2 = 1;
    for (int i = 0; i < n - 1; i++) {
        if (v[i + 1] - v[i] >= 0)
            cnt++;
        else
            cnt = 1;
        ans = max(cnt, ans);

        if (v[i + 1] - v[i] <= 0)
            cnt2++;
        else
            cnt2 = 1;
        ans = max(cnt, ans);
        ans2 = max(cnt2, ans2);
    }
    ans = max(cnt, ans);
    ans2 = max(cnt2, ans2);
    cout << max(ans, ans2);
}