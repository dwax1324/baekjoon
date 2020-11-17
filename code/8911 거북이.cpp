#include <bits/stdc++.h>

using namespace std;

// 구현

// 최댓값 최솟값의 차의 곱을 구해주면된다.

vector<pair<int, int>> v = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int dir = 0;
        int y = 0, x = 0;
        int minY = 0, minX = 0, maxY = 0, maxX = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                dir--;
                if (dir == -1) {
                    dir = 3;
                }
            } else if (s[i] == 'R') {
                dir++;
                if (dir == 4) {
                    dir = 0;
                }
            } else if (s[i] == 'F') {
                y += v[dir].first;
                x += v[dir].second;
            } else {
                y -= v[dir].first;
                x -= v[dir].second;
            }
            minY = min(y, minY);
            minX = min(x, minX);
            maxY = max(y, maxY);
            maxX = max(x, maxX);
            // cout << y << ',' << x << '\n';
        }
        cout << abs(maxX - minX) * abs(maxY - minY) << '\n';
    }
}