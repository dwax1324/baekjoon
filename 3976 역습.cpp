#include <bits/stdc++.h>

using namespace std;

// dp나 다익스트라로 해결 가능 (n log n)인
// naive -> 2**n 가지, 너무느림
// b[i] = min(a[i-1] + passTob[i-1], b[i-1], bDribble[i-1])
// 다익스트라로 풀다가 포기 노드설정해주는데 홀/짝으로 나누면 될듯?
// 구현하다가 떄려침 dp로 해결
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;

    cin >> T;
    while (T--) {
        int passToSecondPlayer[100001];
        int firstPlayerDribble[100001];
        int passToFirstPlayer[100001];
        int secondPlayerDribble[100001];
        int n, l1, l2, s1, s2;
        cin >> n >> l1 >> l2 >> s1 >> s2;
        for (int i = 1; i <= n - 1; i++) {
            cin >> passToSecondPlayer[i];
        }
        for (int i = 1; i <= n - 1; i++) {
            cin >> firstPlayerDribble[i];
        }
        for (int i = 1; i <= n - 1; i++) {
            cin >> passToFirstPlayer[i];
        }
        for (int i = 1; i <= n - 1; i++) {
            cin >> secondPlayerDribble[i];
        }

        int dpA[100001];
        int dpB[100001];
        dpA[0] = l1;
        dpB[0] = l2;

        for (int i = 1; i < n; i++) {
            dpA[i] = min(dpB[i - 1] + passToFirstPlayer[i], dpA[i - 1] + firstPlayerDribble[i]);
            dpB[i] = min(dpA[i - 1] + passToSecondPlayer[i], dpB[i - 1] + secondPlayerDribble[i]);
        }

        cout << min(dpA[n - 1] + s1, dpB[n - 1] + s2) << '\n';
    }
}