#include <bits/stdc++.h>

using namespace std;

// 빈배열을 만든다.
// 1번부터 시작하여 배열의 좌측부터 빈자리를 세어준다
// 빈자리의 숫자가 왼쪽에 자신보다 큰 숫자들의 수이다.
// 이미 채워진 곳은 세지않는다.
// 수가 일치하면 배열에 채워넣는다.
// 수가 오름차순으로 주어지므로 왼쪽에 있는 숫자만큼 자리를 만들어주면 된다.

int main() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int cnt = 0;
        for (int j = 0; j < v.size(); j++) {
            if (v[j]) continue;
            if (cnt == a) {
                v[j] = i + 1;
                break;
            }
            if (v[j] == 0) cnt++;
        }
        // cout << '\n';
    }
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}