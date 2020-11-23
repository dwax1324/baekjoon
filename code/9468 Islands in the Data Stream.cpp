#include <bits/stdc++.h>

using namespace std;

// 수가 커지는 순간에 cnt++하면된다.

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int prev;
        int cnt = 0;
        for (int j = 0; j < 15; j++) {
            int b;
            cin >> b;
            if (j == 0)
                prev = b;
            else {
                if (prev < b) cnt++;
                prev = b;
            }
        }
        cout << a << " " << cnt << '\n';
    }
}