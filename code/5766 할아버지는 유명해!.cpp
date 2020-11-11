#include <bits/stdc++.h>
#define VAL 10001

//단순구현문제
//일등을 제외한 이등들의 갯수를 찾는다

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    while (1) {
        cin >> n >> m;
        if (!n && !m) break;
        int arr[VAL] = {
            0,
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int a;
                cin >> a;
                arr[a]++;
            }
        }

        int MAX = 0;
        for (int i = 1; i < VAL; i++) {
            MAX = max(MAX, arr[i]);
        }
        int MAX2 = 0;
        for (int i = 1; i < VAL; i++) {
            if (arr[i] < MAX) {
                MAX2 = max(MAX2, arr[i]);
            }
        }
        for (int i = 1; i < VAL; i++) {
            if (arr[i] == MAX2) cout << i << " ";
        }
        cout << '\n';
    }
}
