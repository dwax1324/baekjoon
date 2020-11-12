#include <bits/stdc++.h>
#define MAXVAL 1000001

// 정렬문제
// 시간대별로 키보드와 문자를 추가해준다.
// 그 안에서 키보드 번호순으로  정렬한다.

using namespace std;

vector<pair<int, char>> arr[MAXVAL];
int main() {
    int n, m;
    cin >> n >> m;
    int MAX = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        MAX = max(b, MAX);
        arr[b].push_back({a, c});
    }

    for (int i = 0; i <= MAXVAL; i++) {
        sort(arr[i].begin(), arr[i].end());
    }

    for (int i = 0; i <= MAXVAL; i++) {
        if (arr[i].size()) {
            for (int j = 0; j < arr[i].size(); j++) {
                cout << arr[i][j].second;
            }
        }
    }
}