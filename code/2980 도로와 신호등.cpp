#include <bits/stdc++.h>
using namespace std;

// 구현 , 시뮬레이션

// 구조체 배열사용
// 시간 멤버를 하나 더 만들어서
// 빨간불보다 적으면 stop,아니면 go
// 시간이 빨간불+초록불을 넘어가면 0으로 초기화

// 수학적으로 풀기도 가능
// https://mygumi.tistory.com/272 참고/출처

struct tl {
    int d = 0, r = 0, g = 0, t = 0;
};

struct tl arr[1001];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        struct tl t;
        cin >> t.d >> t.r >> t.g;
        arr[t.d] = t;
    }
    // for (int i = 1; i <= 5; i++) {
    //     printf("%d %d %d %d\n", arr[i].d, arr[i].g, arr[i].r, arr[i].t);
    // }

    int cur = 0;
    int cnt = 0;
    while (1) {
        if (cur == m) break;
        cnt++;
        if (arr[cur].r == 0) {
            cur++;
        } else if (arr[cur].t >= arr[cur].r) {
            cur++;
        }
        // cout << cur << " ";
        for (int i = 1; i <= m; i++) {
            arr[i].t++;
            if (arr[i].t >= arr[i].g + arr[i].r) {
                arr[i].t = 0;
            }
        }
    }
    cout << cnt;
}