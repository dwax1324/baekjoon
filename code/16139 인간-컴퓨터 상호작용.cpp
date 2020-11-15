#include <bits/stdc++.h>
using namespace std;

// 부분합
// a~z에 대한 부분합을 만든다
// 인덱스 주의 (첫,끝부분 포함임)

int arr[27][200001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    int n;
    cin >> n;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j <= s.size(); j++) {
            if (s[j] == (char)('a' + i)) {
                arr[i][j + 1] = arr[i][j] + 1;
            } else {
                arr[i][j + 1] = arr[i][j];
            }
        }
    }

    // for (int i = 0; i <= s.size(); i++) {
    //     cout << arr[0][i] << " ";
    // }
    for (int i = 0; i < n; i++) {
        char a;
        int l, r;
        cin >> a >> l >> r;
        cout << arr[a - 'a'][r + 1] - arr[a - 'a'][l] << '\n';
    }
}