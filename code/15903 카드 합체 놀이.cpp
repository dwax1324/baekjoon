#include <bits/stdc++.h>

// 그리디
// 항상 작은것 두개만 더해주면됨
// 우선순위큐사용 (오름차순)

using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        pq.push(a);
    }

    for (long long i = 0; i < m; i++) {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        pq.push(a + b);
        pq.push(a + b);
    }

    long long SUM = 0;
    while (pq.size()) {
        SUM += pq.top();
        pq.pop();
    }

    cout << SUM;
}