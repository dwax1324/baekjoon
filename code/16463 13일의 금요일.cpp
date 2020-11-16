#include <bits/stdc++.h>

// 구현
// 4의 배수이면서 100의 배수이거나 400의 배수이면 윤년(2월이 29일까지) 나머지 28일
// 일주일씩 더하면서 윤년/ 달의 날의 값만큼 빼줬다

using namespace std;

int main() {
    int n;
    cin >> n;
    int m = 1;
    int y = 2019;
    int d = 4;
    int cnt = 0;
    while (1) {
        if (y == n + 1 && m == 1) break;
        if (d == 13) cnt++;
        if (m == 13) {
            m = 1;
            y++;
        }
        d += 7;
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) {
            if (d > 31) {
                d -= 31;
                m++;
            }
        } else if (m == 2) {
            if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
                if (d > 29) {
                    d -= 29;
                    m++;
                }
            } else {
                if (d > 28) {
                    d -= 28;
                    m++;
                }
            }
        } else {
            if (d > 30) {
                d -= 30;
                m++;
            }
        }
    }
    cout << cnt;
}