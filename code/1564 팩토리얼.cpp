#include <bits/stdc++.h>

using namespace std;

// 구현
// 정수론 지식이고 뭐시고
// 그냥 구현하면된다.
// 개빡친다.
// 0을 앞에 채워넣어서 출력해야한다.

unsigned long long go(unsigned long long n) {
    unsigned long long temp = 1;
    for (unsigned long long i = 1; i <= n; i++) {
        temp *= i;
        while (1) {
            if (temp % 10 == 0)
                temp /= 10;
            else
                break;
        }
        temp %= 10000000000000;
    }
    return temp;
}

int main() {
    unsigned long long n;
    cin >> n;
    printf("%05d\n", go(n) % 100000);
}