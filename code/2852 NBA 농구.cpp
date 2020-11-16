#include <bits/stdc++.h>
using namespace std;

// 구현

// 총 게임의 길이가 48분이니 2880초이다.
// 배열을 만들어 기록해준다.
// 입력받으면서 우위가 갈리는 기점을 배열에 기록한다.
// 다시 배열을 돌면서 우위가 갈리는지점부터 또다른 지점까지 채워준다.
// 초마다 세면서 시간을 재고 출력한다.

// 효율적이진않은 코드
// 수학적으로 풀수도 있을거같은데

int arr[3000];

int main() {
    int n;
    cin >> n;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        string b;
        cin >> a >> b;
        if (a == 1)
            s1++;
        else
            s2++;

        int m = stoi(b.substr(0, 2));
        int s = stoi(b.substr(3, 5));
        int tot = m * 60 + s;

        if (s1 > s2) {
            arr[tot] = 1;
        } else if (s2 > s1) {
            arr[tot] = 2;
        } else {
            arr[tot] = 3;
        }
    }

    for (int i = 1; i < 2880; i++) {
        if (arr[i] != 0) continue;
        arr[i] = arr[i - 1];
    }
    int ans1 = 0;
    int ans2 = 0;
    for (int i = 0; i < 2880; i++) {
        if (arr[i] == 1) ans1++;
        if (arr[i] == 2) ans2++;
    }
    printf("%02d:%02d\n%02d:%02d", ans1 / 60, ans1 % 60, ans2 / 60, ans2 % 60);
}