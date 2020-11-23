#include <bits/stdc++.h>

using namespace std;

// N M 중 하나라도 짝수가 존재한다면 승리할 수 있다.

// 아래는 dp로 푼건데
// 어떻게 통과된건진 모르겠네

// int main(){

// }

int dp[101];
vector<pair<int, int>> parse(int a) {
    vector<pair<int, int>> v;
    for (int i = 1; i <= a / 2; i++) {
        v.push_back({i, a - i});
    }
    return v;
}

int main() {
    int n, m;
    cin >> n >> m;
    dp[2] = 1;
    dp[3] = 0;
    for (int i = 4; i <= 100; i++) {
        bool flag = false;
        for (auto x : parse(i)) {
            if (dp[x.first] == 0 && dp[x.second] == 0) {
                // cout << x.first << " " << x.second << '\n';
                dp[i] = 1;
                flag = true;
                break;
            }
        }
        if (flag) continue;
        dp[i] = 0;
    }
    for (int i = 1; i <= 100; i += 2) {
        cout << dp[i] << " " << dp[i + 1] << '\n';
    }
    cout << (max(dp[n], dp[m]) ? "A" : "B");
}