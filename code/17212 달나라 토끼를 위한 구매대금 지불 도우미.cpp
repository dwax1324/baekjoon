#include <bits/stdc++.h>
using namespace std;

// dp 문제
// 동전과 비슷함
// 재귀에서 어떤 함수를 먼저 호출할지 순설를 잘 정해야할듯.

int n;
int dp[100001];

int go(int depth, int cur) {
    if (cur == n) return depth;
    if (cur > n) return 1 << 30;
    if (dp[cur] != -1) {
        return dp[cur];
    }
    int a = go(depth + 1, cur + 1);
    int b = go(depth + 1, cur + 2);
    int c = go(depth + 1, cur + 5);
    int d = go(depth + 1, cur + 7);
    int ret = min({d, c, b, a});
    return dp[cur] = ret;
}

int main() {
    cin >> n;
    fill(dp, dp + 100001, -1);
    cout << go(0, 0);
    for (int i = 0; i <= 12; i++) {
        cout << dp[i] << " ";
    }
}