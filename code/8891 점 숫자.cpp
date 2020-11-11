#include <bits/stdc++.h>

// 고민을 많이한 문제
// 배열 대각선으로 어떻게 채우지하다가
// for문(가로 한번 세로로 한번) + while문(i-1,j-1)이 생각났는데
// 구글링해보니 이중반복문에 변수 세개쓰면서 채울 수 있었다.
// 대각선에 있는 숫자들은 합이 같다(i+j -> A)
// 그러므로 A, i 혹은 j 중 두 값을 알면 나머지 한 값을 알 수 있다.
// 바깥쪽 포문에서 안쪽포문의 값을 빼준다. 이 때 값이 범위를 벗어나면 무시한다.
// 구한값과 안쪽포문의 값으로 대각선을 채울 수 있다.
// 새 변수를 만들어서 구한 값이 범위안에있으면 +1해주면서 채워나간다.

// 주어진 쿼리를 풀어나갈 때마다 배열 전체를 돈다면 시간초과가 난다.
// 각 점의 좌표를 저장해놓으면 o(1)의 시간으로 해결할 수 있다.
// 최대값은 4만을 넘는다.

using namespace std;

pair<int, int> parr[30001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[301][301] = {
        0,
    };
    int n = 300;
    int cnt = 0, num = 0;
    for (int i = 1; i <= n * 2; i++) {
        for (int j = n; j > 0; j--) {
            cnt = i - j;
            if (cnt > n || cnt <= 0) continue;
            num++;
            arr[j][cnt] = num;
            if (num <= 30000)
                parr[num] = {j, cnt};
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << arr[parr[a].first + parr[b].first][parr[a].second + parr[b].second] << '\n';
    }
}