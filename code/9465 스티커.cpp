
// 약간 그리디하게 푸는 경우
// dp를 사용하지만 첫 열의 두 스티커가 시작점임
// 대각선으로 움직이면서 스티커를 선택하는데
// 한칸 앞으로, 두칸앞으로 움직일 수 있다
// (세칸앞부턴 한 칸앞이랑 겹치면서 한칸앞보다 무조건 적어진다.)

// #include <bits/stdc++.h>

// using namespace std;

// #define MAX 100010

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int arr[2][MAX] = {
//             0,
//         };
//         int dp[2][MAX] = {
//             0,
//         };
//         int n;
//         cin >> n;
//         for (int i = 0; i < 2; i++) {
//             for (int j = 0; j < n; j++) {
//                 cin >> arr[i][j];
//             }
//         }

//         dp[0][0] = arr[0][0];
//         dp[1][0] = arr[1][0];
//         dp[0][1] = arr[0][1] + arr[1][0];
//         dp[1][1] = arr[1][1] + arr[0][0];

//         for (int i = 2; i < n; i++) {
//             dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
//             dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
//         }
//         cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
//     }
// }

// dp스럽게 모든 경우를 다 체크
// 위쪽스티커 , 아래쪽스티커 , 선택하지않음 을 저장하며 최대값을 갱신
// 탑다운
// #include <bits/stdc++.h>

// using namespace std;

// #define MAX 100000

// int arr[2][MAX];
// int dp[MAX][3];
// int n;

// int go(int column, int state) {
//     if (column == n) return 0;
//     if (dp[column][state] != -1) return dp[column][state];

//     int res = go(column + 1, 0);
//     if (state != 1) res = max(res, go(column + 1, 1) + arr[0][column]);
//     if (state != 2) res = max(res, go(column + 1, 2) + arr[1][column]);
//     dp[column][state] = res;
//     return res;
// }

// int main() {
//     int T;
//     scanf("%d", &T);
//     while (T--) {
//         scanf("%d", &n);
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < 3; j++) {
//                 dp[i][j] = -1;
//             }
//         }
//         for (int j = 0; j < 2; j++) {
//             for (int i = 0; i < n; i++) {
//                 scanf("%d", &arr[j][i]);
//             }
//         }

//         printf("%d\n", go(0, 0));
//     }
// }

//바텀업

// #include <bits/stdc++.h>

// using namespace std;
// #define MAX 100001

// int main() {
//     int T;
//     scanf("%d", &T);
//     while (T--) {
//         int n, arr[2][MAX], dp[MAX][3] = {
//                                 0,
//                             };

//         scanf("%d", &n);

//         for (int i = 0; i < 2; i++) {
//             for (int j = 0; j < n; j++) {
//                 scanf("%d", &arr[i][j]);
//             }
//         }

//         for (int i = 0; i < n; i++) {
//             dp[i + 1][0] = max(dp[i + 1][0], max(dp[i][0], max(dp[i][1], dp[i][2])));
//             dp[i + 1][1] = max(dp[i + 1][0], max(dp[i][0], dp[i][2]) + arr[0][i]);
//             dp[i + 1][2] = max(dp[i + 1][0], max(dp[i][0], dp[i][1]) + arr[1][i]);
//         }
//         printf("%d\n", max(dp[n][0], max(dp[n][1], dp[n][2])));
//     }
// }