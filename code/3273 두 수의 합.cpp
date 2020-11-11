#include <bits/stdc++.h>

// 이분탐색 , 투포인터문제
// 결국 나이브하게 이중반복문 O(n**2)의 최적화를 시키는 문제
// 이분탐색으로 풀었지만 투포인터(앞뒤로오는)로도 풀기가능.

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
    int x;
    cin >> x;

    sort(v.begin(), v.end());

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] < x) {
            if (binary_search(v.begin(), v.end(), x - v[i])) cnt++;
        }
    }
    cout << cnt / 2;
}