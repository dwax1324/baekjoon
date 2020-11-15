#include <bits/stdc++.h>
using namespace std;

// 구현 시뮬레이션

// 규칙1,2는 쉬우니 그냥 구현하고
// 규칙3만 위배되는 8가지 경우를 뽑아내어 따로검사한다.

pair<pair<int, int>, int> arr[10] = {
    {{1, 3}, 2},
    {{4, 6}, 5},
    {{7, 9}, 8},
    {{1, 7}, 4},
    {{2, 8}, 5},
    {{3, 9}, 6},
    {{1, 9}, 5},
    {{3, 7}, 5},
};

bool vi[10];
int main() {
    int n;
    cin >> n;
    int ret = 1;
    int prev;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (vi[a]) ret = -1;
        if (i > 0) {
            for (int j = 0; j < 8; j++) {
                int f = arr[j].first.first;
                int s = arr[j].first.second;
                int m = arr[j].second;
                if ((f == a && s == prev) || (f == prev && s == a)) {
                    for (int z = 0; z < 10; z++) {
                        if (!vi[m]) {
                            ret = -1;
                        }
                    }
                }
            }
        }
        vi[a] = true;
        prev = a;
    }

    if (ret == -1)
        cout << "NO";
    else
        cout << "YES";
}