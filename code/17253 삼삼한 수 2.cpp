#include <bits/stdc++.h>

// num: 2 , in ternary: 2
// num: 5 , in ternary: 12
// num: 8 , in ternary: 22
// num: 11 , in ternary: 102
// num: 14 , in ternary: 112
// num: 17 , in ternary: 122
// num: 20 , in ternary: 202
// 1 1
// 3 10
// 9 100
// 27 1000
// 81 10000

// 3진수로 나타내면 수에 2가들어있으면 3의제곱의 합으로 아예 표현이 불가능하다.
// 그것만 걸러내주면된다.

using namespace std;

int main() {
    long long n;
    cin >> n;

    if (!(n | 0)) {
        cout << "NO";
        return 0;
    }
    while (n) {
        if (n % 3 == 2) {
            cout << "NO";
            return 0;
        }
        n /= 3;
    }
    cout << "YES";
}