#include <bits/stdc++.h>

using namespace std;

// 부분합
// 왼쪽부분합 + 오른쪽부분합 + 브릿지

// 이걸 왜생각을 못헀을까잉~
// dp로풀다가 갈아엎었다.

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long bridge[100001];
    long long A[100001];
    long long B[100001];

    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> bridge[i];
    }

    for (long long i = 1; i <= n - 1; i++) {
        long long a;
        cin >> a;
        A[i] = A[i - 1] + a;
    }

    for (long long i = 1; i <= n - 1; i++) {
        long long a;
        cin >> a;
        B[i] = B[i - 1] + a;
    }

    vector<pair<long long, long long>> v;
    for (long long i = 1; i <= n; i++) {
        long long a = (A[i - 1] - A[0]);
        long long b = bridge[i];
        long long c = (B[n - 1] - B[i - 1]);
        v.push_back({a + b + c, i});
    }

    sort(v.begin(), v.end(), cmp);
    cout << v[0].second << " " << v[0].first;
}