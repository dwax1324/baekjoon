#include <bits/stdc++.h>

using namespace std;

// 좌표압축
// 처음보는 알고리즘
// 좌표의 범위가 크고 불필요한 부분이 많을 때 압축한다고 한다.
// 세그먼트 트리 등에 이용된다고 한다.
// 절대좌표를 상대좌표로 바꿔주는건가? 좀 더 공부해야봐겠다

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> v2(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v2[i] = v[i];
    }

    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());

    for (auto x : v) {
        cout << lower_bound(v2.begin(), v2.end(), x) - v2.begin() << " ";
    }
}