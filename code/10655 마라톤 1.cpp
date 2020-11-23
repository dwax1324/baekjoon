#include <bits/stdc++.h>

using namespace std;

// 구현

// 각 거리의 진짜거리와 하나빠졌을때의 거리를 구해서
// 그 최댓값을 구한다.
// 총거리에서 보정된 값의 거리를 뺀다.

int main() {
    int n;
    vector<pair<int, int>> v;
    cin >> n;
    int totDistance = 0;
    pair<int, int> cur;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
        if (i >= 1) {
            totDistance += (abs(x - cur.first) + abs(y - cur.second));
        }
        cur.first = x;
        cur.second = y;
    }

    vector<pair<int, int>> v2;
    int skip = 0;
    for (int i = 1; i < n - 1; i++) {
        int curX = abs(v[i].first - v[i - 1].first) + abs(v[i].first - v[i + 1].first);
        int curY = abs(v[i].second - v[i - 1].second) + abs(v[i].second - v[i + 1].second);

        int possibleX = abs(v[i - 1].first - v[i + 1].first);
        int possibleY = abs(v[i - 1].second - v[i + 1].second);
        // printf("curX : %d curY : %d possilbeX : %d possibleY :%d\n", curX, curY, possibleX, possibleY);
        // cout << (curX + curY) - (possibleX + possibleY) << " ";
        skip = max((curX + curY) - (possibleX + possibleY), skip);
    }
    // cout << totDistance;
    cout << totDistance - skip;
}