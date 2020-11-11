#include <bits/stdc++.h>

// 단순 구현
// 배엻 하나를 써서 구현하면 cascade된다. 복사하자
// 앞 != 뒤로 썻었는데 그러면 전진중인지 후퇴중인지 구별이 안됨.
// 앞 == 1 && 뒤 == 2 이런식으로 상태를 특정해야함

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    pair<char, int> tot[60];
    for (int i = 0; i < n; i++) {
        cin >> tot[i].first;
        tot[i].second = 1;
    }
    reverse(tot, tot + n);
    for (int i = n; i < n + m; i++) {
        cin >> tot[i].first;
        tot[i].second = 2;
    }
    int t;
    cin >> t;
    pair<char, int> temp[60];
    for (int j = 0; j < t; j++) {
        for (int i = 0; i < n + m; i++) {
            temp[i] = tot[i];
        }
        for (int i = 0; i < n + m - 1; i++) {
            if ((temp[i].second == 1 && temp[i + 1].second == 2)) {
                swap(tot[i], tot[i + 1]);
            }
        }
    }
    for (int i = 0; i < n + m; i++) {
        cout << tot[i].first;
    }
    // cout << '\n';
}