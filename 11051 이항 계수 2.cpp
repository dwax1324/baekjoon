#include <bits/stdc++.h>

// 조합공식을 이용해 풀었다.
// 모듈러의 연산
// 나누기는 역원을 구하고 역원곽 분모를 다시 곱해서 모듈러해주면된다.
// 자세한건 검색 ㄱㄱ
// dp는 간단하게 팩토리얼처럼 이전 값에서 i를계속 곱해준다.
// 파스칼의 삼각형으로 풀 수도 있다.

using namespace std;
const int MAX = 10007;
int findNum(int x) {
    for (int i = 1; i <= MAX; i++) {
        if ((x * i) % MAX == 1) return i;
    }
    return -1;
}

int main() {
    int n, r;
    cin >> n >> r;
    int dp[1001];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = ((dp[i - 1] % MAX) * (i % MAX)) % MAX;
    }

    int denominator = ((dp[n - r] % MAX) * (dp[r] % MAX)) % MAX;
    printf("%d", (((dp[n]) * findNum(denominator)) % MAX));
}