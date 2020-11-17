#include <bits/stdc++.h>

using namespace std;

// 트리 재귀

// 이분탐색? 분할정복?으로 풀었다
// 검색해보면 사람들 각기 다 다른방법으로 푼다.
// 아직은 이런문제가 어렵다.

vector<int> arr[11];
vector<int> v;
void go(int l, int r, int depth) {
    if (l > r) return;
    if (l == r) {
        // cout << v[l] << " ";
        arr[depth].push_back(v[l]);
        return;
    }

    int mid = (l + r) / 2;
    // cout << v[mid] << " ";
    arr[depth].push_back(v[mid]);

    go(l, mid - 1, depth + 1);
    go(mid + 1, r, depth + 1);
    return;
}

int main() {
    int k;
    cin >> k;
    int len = (1 << k) - 1;
    v.resize(len);
    for (int i = 0; i < len; i++) {
        cin >> v[i];
    }
    go(0, len, 1);

    for (int i = 1; i <= k; i++) {
        for (auto x : arr[i]) {
            cout << x << " ";
        }
        cout << '\n';
    }
}