#include <bits/stdc++.h>

using namespace std;

// 메모이제이션

// dp의 점화식과 기저사례를 다 준다.
// 거기에 메모이제이션만 얹으면 정답처리된다.
// 매번 배열을 초기화시켜서 오답을 받았다.
// 저장된값은 다른 입력이 들어와도 계속 쓸 수 있다.

int dp[101][101][101];
int go(int a, int b, int c) {
    int i = a + 50, j = b + 50, k = c + 50;
    if (dp[i][j][k]) return dp[i][j][k];
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (a > 20 || b > 20 || c > 20) return dp[i][j][k] = go(20, 20, 20);
    if (a < b && b < c) {
        return dp[i][j][k] = go(a, b, c - 1) + go(a, b - 1, c - 1) - go(a, b - 1, c);
    }
    return dp[i][j][k] = go(a - 1, b, c) + go(a - 1, b - 1, c) + go(a - 1, b, c - 1) - go(a - 1, b - 1, c - 1);
}

int main() {
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c)) {
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%d, %d, %d) = %d\n", a, b, c, go(a, b, c));
    }
}