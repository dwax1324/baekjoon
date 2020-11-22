#include <bits/stdc++.h>
using namespace std;

// 그리디

// 앞뒤 간격이 가장 많이 차이나는 순으로 자른다.
// k개의 그룹을 만들어야하면 k-1번 자르면 되므로
// 크기순 정렬 후 k-1개를 제외한 나머지를 합한다.

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    long long arr[300001];
    long long prev, cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (i == 0) {
            prev = a;
        } else {
            arr[cnt++] = a - prev;
            prev = a;
        }
    }

    sort(arr, arr + cnt);
    long long sum = 0;
    for (int i = 0; i < n - m; i++) {
        // printf("%d ", arr[i]);
        sum += arr[i];
    }
    printf("%d", sum);
}