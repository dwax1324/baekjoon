#include <bits/stdc++.h>

using namespace std;

// 구현 트리
// 완전이진트리다.
// 트리를 그려보면 자신이 홀수면 (a-1 /2) 짝수면 a/2로  부모를 찾을 수 있다.
// 주어진 두 수의 부모를 따라올라가며 배열에 저장해두고
// 두 배열을 비교하며 처음으로 같은 값을 만나면 *10해ㅅㅓ 출력해준다.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vector<int> v, v2;
        v.push_back(a);
        v2.push_back(b);
        while (a != 1) {
            if (a % 2 == 1) {
                a = (a - 1) / 2;
                v.push_back(a);
            } else {
                a = a / 2;
                v.push_back(a);
            }
        }
        while (b != 1) {
            if (b % 2 == 1) {
                b = (b - 1) / 2;
                v2.push_back(b);
            } else {
                b = b / 2;
                v2.push_back(b);
            }
        }
        int ans = 0;
        int flag = false;
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                if (v2[j] < v[i]) break;
                if (v[i] == v2[j]) {
                    ans = v[i];
                    flag = true;
                    break;
                }
                if (flag) break;
            }
        }
        cout << ans * 10 << '\n';
    }
}