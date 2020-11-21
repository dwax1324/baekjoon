#include <bits/stdc++.h>

using namespace std;

// 시도1
// pq를 써서 최댓값 +1의 동점자수를 맞춰보려고함.
// 그리디한 방법이었지만 반례가 쉽게나옴

// 시도 2
// dp
// 역순정렬한다.
// 한 플레이어에게 최대점수를 주고싶으면 n을 줘야한다.
// 나머지는 1부터n-1까지 순서대로준다(클수록 작은값을 더한다)
// 브루트포스로 풀면 o(n^2logn)이 나온다.
// dp를 사용하면 o(nlogn)에 풀수있다.

// dp[i] = max(dp[i-1], arr[i]+i)
// 만약 i번째 선수에게 최댓값을 더했을때 dp값보다 크거나 같으면 정답에 1을 증가시킴

bool cmp(int a, int b) { return a > b; }

int arr[300002];
int dp[300002];
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    sort(arr + 1, arr + n + 1, cmp);

    for (int i = 1; i <= n; i++) {
        // printf("%d", *(arr + i));
    }
    int ans = 0;
    dp[0] = arr[1] + 1;
    for (int i = 1; i <= n; i++) {
        ans += (arr[i] + n >= dp[i - 1]);
        dp[i] = max(dp[i - 1], arr[i] + i);
    }

    // for (int i = 1; i <= n; i++) {
    //     printf("%d ", dp[i]);
    // }
    printf("%d", ans);
}