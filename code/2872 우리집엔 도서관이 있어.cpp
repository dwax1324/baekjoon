#include <bits/stdc++.h>

// 가장 숫자가 큰 책의 번호 앞에 연속된 숫자가 몇개있는지 세면 된다.(안붙어있어도됨)
// 전체 값 - 찾은 값 = 답

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    int MAX = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        MAX = max(v[i], MAX);
    }
    int cnt = 0;
    for (int i = n; i >= 1; i--) {
        if (v[i] == MAX) {
            cnt++;
            MAX--;
        }
    }
    cout << n - cnt;
}