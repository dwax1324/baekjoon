#include <bits/stdc++.h>

using namespace std;

// 구현 유클리드호제법 최대공약수찾기
// 최대공약수를 찾아서 기약분수꼴로 나타내 출력한다.

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int a, b;
    int c, d;
    cin >> a >> b >> c >> d;

    int numerator = a * d + c * b;
    int denominator = b * d;
    int euclid = gcd(denominator, numerator);

    cout << numerator / euclid << '\n'
         << denominator / euclid;
}