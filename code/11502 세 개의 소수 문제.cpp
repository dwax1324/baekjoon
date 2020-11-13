#include <bits/stdc++.h>

using namespace std;

// 조합탐색문제
// 소수 1000까지 구해놓고
// 3개를 합해서 k값이 될수 있는지 확인한다.
// 169C3 = 790244

bool isPrime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

vector<int> primes;
int k;
bool found = false;
void go(int depth, vector<int> v) {
    if (depth == 3) {
        if (v[0] + v[1] + v[2] == k) {
            sort(v.begin(), v.end());
            cout << v[0] << " " << v[1] << " " << v[2] << '\n';
            found = true;
        }
        return;
    }

    for (int i = 0; i < primes.size(); i++) {
        v.push_back(primes[i]);
        go(depth + 1, v);
        if (found) return;
        v.pop_back();
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= 1000; i++) {
        if (isPrime(i)) primes.push_back(i);
    }
    while (n--) {
        cin >> k;
        found = false;
        go(0, {});
    }
}