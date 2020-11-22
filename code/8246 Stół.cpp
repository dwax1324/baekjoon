#include <bits/stdc++.h>
using namespace std;

// 케이스워크하다가 숨넘어갈뻔
// 생각이 꼬이기 시작하면 끝도없이 꼬이는 듯
// 음수가 넘어갈 수 있으니 0으로 보정해주면 된다.

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a / c) * (b / c) - max(0, a / c - 2) * max(0, b / c - 2);
}

// int main() {
//     int a, b, k;
//     scanf("%d%d%d", &a, &b, &k);

//     int x = a / k;
//     int y = b / k;
//     if (a > k && b > k) {
//         printf("%d", 2 * x + 2 * y - 4);
//     }else if (k > b || k > a) {
//         printf("0");
//     } else if (k == a && a == b) {
//         printf("1");
//     } else if (a == k && b > k) {
//         printf("%d", b / k);
//     } else if (b == k && a > k) {
//         printf("%d", a / k);
//     }
// }