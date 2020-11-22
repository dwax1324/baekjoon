#include <bits/stdc++.h>
using namespace std;

// 수학

// 3진수로 수를 표현하면
// 3의 제곱은 1, 10, 100, 100 ....
// 주어진 수가 3진수로 표현했을 때 2가들어있으면 오답이다.

int main() {
    int n;
    scanf("%d", &n);

    if (!(n | 0)) return printf("NO"), 0;
    while (n) {
        if (n % 3 == 2) {
            return printf("NO"), 0;
        }
        n /= 3;
    }
    printf("YES");
}