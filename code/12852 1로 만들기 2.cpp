#include <bits/stdc++.h>

using namespace std;

// dp bfs
// dp + 역추적

// dp 자취배열에 인덱스를 넣어준다.
// 목표지점에 -1을 넣어주고 각 인덱스를 저장한다.
// 그리고 n이 -1이 될 때까지 n = trail[n]을 출력하면 역추적이 가능하다.

// bfs는 구조체에 벡터를넣어 자취를 넣어줬다. -> 효율이 굉장히 안좋다. 932ms

int trail[1000001];
int dp[1000001];

void go(int n) {
    dp[1] = 0;
    trail[1] = -1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        trail[i] = i - 1;

        if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
            dp[i] = dp[i / 2] + 1;
            trail[i] = i / 2;
        }
        if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
            dp[i] = dp[i / 3] + 1;
            trail[i] = i / 3;
        }
    }
}

int main() {
    int n;
    cin >> n;
    go(n);
    cout << dp[n] << "\n";

    for (int i = 1; i <= n; i++) {
        cout << trail[i] << " ";
    }

    while (n != -1) {
        // cout << n << " ";
        n = trail[n];
    }
}

////// BFS
// struct info {
//     int cur;
//     vector<int> trail;
//     int sum;
// };

// // bool vi[1000001];
// int main() {
//     ios_base::sync_with_stdio(false);
//     cout.tie(NULL);
//     cin.tie(NULL);
//     int n;
//     cin >> n;

//     queue<info> q;

//     q.push({n, {n}, 0});
//     // vi[n] = true;
//     while (q.size()) {
//         info cur = q.front();
//         q.pop();
//         if (cur.cur == 1) {
//             cout << cur.sum << '\n';
//             for (auto x : cur.trail) {
//                 cout << x << " ";
//             }
//             // cout << '\n';
//             return 0;
//         }
//         if (cur.cur % 3 == 0) {
//             if (cur.cur / 3 >= 1) {
//                 // if (vi[cur.cur / 3]) continue;
//                 cur.trail.push_back(cur.cur / 3);
//                 q.push({cur.cur / 3, cur.trail, cur.sum + 1});
//                 cur.trail.pop_back();
//             }
//         }
//         if (cur.cur % 2 == 0) {
//             if (cur.cur / 2 >= 1) {
//                 // if (vi[cur.cur / 2]) continue;
//                 cur.trail.push_back(cur.cur / 2);
//                 q.push({cur.cur / 2, cur.trail, cur.sum + 1});
//                 cur.trail.pop_back();
//             }
//         }
//         if (cur.cur - 1 >= 1) {
//             // if (vi[cur.cur - 1]) continue;
//             cur.trail.push_back(cur.cur - 1);
//             q.push({cur.cur - 1, cur.trail, cur.sum + 1});
//             cur.trail.pop_back();
//         }
//     }
// }