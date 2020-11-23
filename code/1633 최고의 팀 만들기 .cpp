#include <bits/stdc++.h>

using namespace std;

// dp mcmf

// 어렵.. 재귀어렵다..
// 백트래킹 dp

// mcmf로도 풀수있다는데 아직 잘 모르겠고
// dp도 바텀업으로 짜다가 포기하고
// 구글링하여 힌트를얻었다.
// 기본적인 로직은 백트래킹+ dp이다.

int dp[1002][16][16];
int white[1002], black[1002];
int n;

int go(int w, int b, int cur) {
    if (cur == n) return 0;
    int &ret = dp[cur][w][b];
    if (ret) return ret;
    if (w < 15) {
        ret = max(ret, go(w + 1, b, cur + 1) + white[cur]);
    }
    if (b < 15) {
        ret = max(ret, go(w, b + 1, cur + 1) + black[cur]);
    }
    ret = max(ret, go(w, b, cur + 1));
    return ret;
}

int main() {
    n = 0;
    while (~scanf("%d%d", &white[n], &black[n])) {
        n++;
    }
    cout << go(0, 0, 0);
}