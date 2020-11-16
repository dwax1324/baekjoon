#include <bits/stdc++.h>

// 그리디

// 차례대로 가장 앞의 사람이 가장 멀리있는 햄버거를 먹으면 된다.

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'P') {
            for (int j = i - k; j <= i + k; j++) {
                if (j < 0 || j >= s.size()) continue;
                if (s[j] == 'H') {
                    s[j] = '@';
                    cnt++;
                    break;
                }
            }
        }
    }
    cout << cnt;
}