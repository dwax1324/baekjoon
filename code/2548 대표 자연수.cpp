#include <bits/stdc++.h>
using namespace std;

// 정렬
// 중앙값을 출력하면된다.
// 브루트포스로 풀어도 통과된다.
// 자료가 약한지 2억에 1초라 통과안될거같은데 통과됐음.

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if (n % 2 == 1) {
        cout << v[n / 2];
    } else {
        cout << v[n / 2 - 1];
    }
}