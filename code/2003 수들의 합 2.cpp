#include <bits/stdc++.h>

// 구간 합 배열
// 인덱스 신경 잘써줘야함
// 앞으로 +1 or 뒤로 +1

using namespace std;

vector<long long> pv(10001);

int main() {
    long long n, m;
    cin >> n >> m;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        pv[i + 1] = pv[i] + a;
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (pv[j] - pv[i] == m) cnt++;
        }
    }
    cout << cnt;
}