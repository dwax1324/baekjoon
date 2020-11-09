#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int arr[10001];
    const int INF = 1 << 30;
    for (int i = 1; i <= k; i++) {
        arr[i] = INF;
    }

    // 배열[동전] = 1회
    for (int i = 0; i < n; i++) {
        if (v[i] <= 10000) arr[v[i]] = 1;
    }

    // 1부터 시작하여 i+동전값 만큼의 최솟값을 갱신한다.
    for (int i = 1; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (i + v[j] > k) continue;
            arr[i + v[j]] = min(arr[i + v[j]], arr[i] + 1);
        }
    }
    printf("%d", arr[k] == INF ? -1 : arr[k]);
}