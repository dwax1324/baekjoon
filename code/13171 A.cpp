#include <bits/stdc++.h>

// 분할정복
// 재귀는 아릅답다
// 로그도 아름답다

using namespace std;

long long mod = 1e9 + 7;

long long go(long long a, long long b) {
    if (b == 0) return 1;

    long long res = go(a, b / 2);
    if (b % 2 == 0) {
        return ((res % mod) * (res % mod)) % mod;
    } else {
        return ((((res % mod) * (res % mod)) % mod) * (a % mod) % mod) % mod;
    }
}

int main() {
    long long a, x;
    cin >> a >> x;
    cout << go(a, x);
}