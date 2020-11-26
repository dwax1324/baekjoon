#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

// 이분탐색 파라메트릭서치

// l->1 , r-> maxR * peoples
// 체크 -> n분아래로의 가능한 사람의 수
// 자료형

ull n, m;
vector<ull> v;
bool check(ull a) {
    ull cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += a / v[i];
    }
    return cnt >= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    ull l = 1;
    ull r = v[v.size() - 1] * m;
    ull ans = r;
    while (l <= r) {
        ull mid = (l + r) / 2;

        if (check(mid)) {
            if (ans > mid) {
                ans = mid;
            }
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}