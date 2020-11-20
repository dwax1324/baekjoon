#include <stdio.h>
#include <stdlib.h>
#define ull unsigned long long

// 수학 확률 유클리드호제법

// 2개의 쿠폰으로 시켜먹을때의 주문해야하는 시도는
// 2*(1/2+ 1/1)이다.
// n*(1/n + 1/n-1 .... 1/1)
// (매번 내가 시켜먹을 때의 확률의 합) * n번이다.
// 계산하다보면 수가 굉장히 커지는데
// 계산을 하면서 기약분수로 고쳐줘야한다.
// 계산을 다하고하면 usigned long long의 범위조차 초과한다
// 그리고 출력이 까다롭다

ull gcd(ull a, ull b) {
    return b ? gcd(b, a % b) : a;
}

char* line(ull a, ull b) {
    ull k = a > b ? a : b;
    int cnt = 0;
    while (k) {
        cnt++;
        k /= 10ULL;
    }
    char* arr = malloc(sizeof(char) * cnt);
    for (int i = 0; i < cnt; i++) {
        arr[i] = '-';
    }
    return arr;
}

char* spaces(ull a) {
    int cnt = 0;

    while (a) {
        cnt++;
        a /= 10ULL;
    }
    char* arr = malloc(sizeof(char) * cnt);
    for (int i = 0; i < cnt + 1; i++) {
        arr[i] = ' ';
    }
    return arr;
}

int main() {
    ull n;
    while (~scanf("%lld", &n)) {
        ull sumA = 0;
        ull sumB = 0;
        for (int i = 1; i <= n; i++) {
            ull a, b;
            a = 1ULL;
            b = (ull)i;

            ull k;
            if (i == 1) {
                sumA = a;
                sumB = b;
                k = gcd(sumB, sumA);
                sumA /= k;
                sumB /= k;
            } else {
                sumA = sumA * b + a * sumB;
                sumB *= b;
                k = gcd(sumB, sumA);
                sumA /= k;
                sumB /= k;
            }
        }
        sumA *= n;
        // printf("%llu", sumB);
        int k = gcd(sumA, sumB);
        if (sumA % sumB == 0) {
            printf("%lld\n", sumA / sumB);
        } else {
            char* spcs = spaces(sumA / sumB);
            char* lines = line((sumA % sumB) / k, sumB / k);
            printf("%s%lld\n%lld %s\n%s%lld\n", spcs, (sumA % sumB) / k, sumA / sumB, lines, spcs, sumB / k);
        }
        // printf("%d/%d", sumA / sumB);
    }
}