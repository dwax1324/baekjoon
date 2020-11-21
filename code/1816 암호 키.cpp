#include <bits/stdc++.h>

using namespace std;

// 소수 에라토스테네스의 체
// 10^6 이하의 소수를 구해서
// 나누어 떨어지면 암호키가 아니다.

bool vi[1000001];
vector<long long> v;
void sieve() {
    for (int i = 2; i <= 1000000; i++) {
        if (vi[i]) continue;
        vi[i] = true;
        v.push_back(i);
        for (int j = 2 * i; j <= 1000000; j += i) {
            vi[i] = true;
        }
    }
}

int main() {
    sieve();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        long long k;
        cin >> k;
        for (int j = 0; j < v.size(); j++) {
            if (k % v[j] == 0) flag = false;
        }
        if (!flag)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
