#include <bits/stdc++.h>

using namespace std;

//  최대공약수를 구해서
//  최대공약수의 약수만큼 값을 나누고 출력해준다.

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int n, m;
    cin >> n >> m;
    int k = gcd(n, m);
    set<int> SET;
    SET.insert(k);
    // cout << k;
    for (int i = 1; i * i <= k; i++) {
        if (k % i == 0) {
            SET.insert(i);
            SET.insert(k / i);
        }
    }
    for (auto x : SET) {
        printf("%d %d %d\n", x, n / x, m / x);
    }
}