#include <bits/stdc++.h>
using namespace std;

// 정수론
// 약수찾기 문제

// 약수를 찾은 후 n- (자신을 제외한 마지막 약수)

vector<int> v;
void divisor(int x) {
    for (int i = 1; i * i <= x; i++) {
        if (i * i == x) {
            v.push_back(i);
        } else if (x % i == 0) {
            v.push_back(i);
            v.push_back(x / i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    divisor(n);
    sort(v.begin(), v.end());
    cout << v[v.size() - 1] - v[v.size() - 2];
    for (auto x : v) cout << x << " ";
}