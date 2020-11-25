#include <bits/stdc++.h>

using namespace std;

//dp

// 백트래킹 + dp로 풀수있다.
// 자두가 떨어지는 곳이라면 +1
int dp[1001][31][3];

int n, m;
vector<int> v;
int go(int depth, int mvs, int tree) {
    if (depth == n) return 0;
    int& ret = dp[depth][mvs][tree];
    if (ret != -1) return ret;

    // 만약 현재위치가 자두라면
    if (tree == v[depth]) {
        // 제한횟수 밑이라면 둘중 하나 ( 제자리 +1)
        if (mvs < m) {
            ret = max(go(depth + 1, mvs + 1, tree ^ 1), go(depth + 1, mvs, tree) + 1);
            //초과했으면 가만히
        } else {
            ret = go(depth + 1, mvs, tree) + 1;
        }
        //아니라면
    } else {
        // (다음자리 +1)
        if (mvs < m) {
            ret = max(go(depth + 1, mvs + 1, tree ^ 1) + 1, go(depth + 1, mvs, tree));
        } else {
            ret = go(depth + 1, mvs, tree);
        }
    }
    return ret;
}

int main() {
    cin >> n >> m;
    v.resize(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }
    cout << go(0, 0, 0);
}