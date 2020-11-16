#include <bits/stdc++.h>
using namespace std;

// 구현 그리디
// 열량/가격 의 최대값을 구해야하기 때문에
// 열량은 높이고 가격은 낮춰야한다.
// 브루트포스로 풀면 시간초과가난다 (100C0 .... 100C100)
// 같은 가격대에서는 가장 높은 열량순으로 뽑아주면 된다.

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int c;
    cin >> c;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());
    int ans = c / (a);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j <= i; j++) {
            sum += v[j];
        }

        ans = max(ans, (c + sum) / (a + b * (i + 1)));
    }
    cout << ans;
}