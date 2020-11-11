#include <bits/stdc++.h>

// 단순구현
// 같은번호가 두개이상 있는지 한단위씩 끊어서 체크한다.

using namespace std;

bool isSame(int x) {
    int arr[10];
    fill(arr, arr + 10, 0);
    while (x) {
        arr[x % 10]++;
        x /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (arr[i] >= 2) return true;
    }
    return false;
}

int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        int cnt = 0;
        for (int i = a; i <= b; i++) {
            if (!isSame(i)) cnt++;
        }
        printf("%d\n", cnt);
    }
}