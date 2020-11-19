#include <bits/stdc++.h>

using namespace std;

// 구현
// 각 행,열별로 최댓값을 구하고 그외 나머짓값의 합을 구하면 된다.

// 시도 1 시간초과
// 3중포문사용

// 시도2 우선순위큐사용
// long long써줬는데도 틀렸습니다 떠서
// 뭔가하고 봤는데 accmumulate할때 0만쓰면 int형이 반환된다.
// 0LL써야하고 함수쓸때 조심하자

long long arr[1001][1001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    long long SUM = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            SUM += arr[i][j];
        }
    }

    long long ans = 0;
    set<long long> v;
    for (int i = 0; i < n; i++) {
        priority_queue<long long> pq;
        for (int j = 0; j < m; j++) {
            pq.push(arr[i][j]);
        }
        v.insert(pq.top());
    }

    for (int i = 0; i < m; i++) {
        priority_queue<long long> pq;
        for (int j = 0; j < n; j++) {
            pq.push(arr[j][i]);
        }
        v.insert(pq.top());
    }

    cout << SUM - accumulate(v.begin(), v.end(), 0LL);
}