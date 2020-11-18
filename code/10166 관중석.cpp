#include <bits/stdc++.h>

using namespace std;

// 각 D마다 360/D를 하여 일정한 간격의 위치를 기록하려했으나
// 소수점오차로 인해 실패함

// 그냥 아예 나누면 안된다.

// 똑같은 아이디어로 기약분수로 고치면 정답이란다.
// 실수형 계산은 되도록 피하는걸로

// 먼저 D값에 대해서 각각의 값들은
// 1/1 1/2, 2/2, 1/3 , 2/3, 3/3.. 등으로 나타낼 수 있다.
// 이 과정에서 기약분수로 나타냈을 때의 겹치는 수가 없이의 갯수가 정답이다.

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    double a, b;
    cin >> a >> b;
    set<pair<int, int>> SET;
    for (int i = a; i <= b; i++) {
        for (int j = 1; j <= i; j++) {
            int k = gcd(i, j);
            SET.insert({i / k, j / k});
        }
    }
    cout << SET.size();
}