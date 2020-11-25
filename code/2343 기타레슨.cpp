#include <bits/stdc++.h>

using namespace std;

// 이분탐색, 파라메트릭 서치

// 이분탐색을 진행해주는데
// l을 1로 잡아주면 큰일남!~
// 곡중의 가장 큰값으로 해야한다. (분할될 수 없기 때문)
// 나머지는 이분탐색이랑 똑같다
// cnt++ 잘해야함

vector<int> v;
int n, m;
bool check(int k) {
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (sum + v[i] > k) {
            sum = 0;
            cnt++;
        }
        sum += v[i];
    }
    if (sum > 0) cnt++;
    // cout << cnt << " ";
    // cout << '\n';
    return cnt <= m;
}

int main() {
    cin >> n >> m;
    v.resize(n);
    int sum = 0;
    int MAX = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        MAX = max(v[i], MAX);
        sum += v[i];
    }

    int l = MAX;
    int r = sum;
    int ans = 1 << 30;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (check(mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}