#include <bits/stdc++.h>
//////////////////////////////////////////////
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define FOR(j, k) for (int i = j; i < k; i++)
#define RFOR(j, k) for (int i = j - 1; i >= k; i--)
using namespace std;
void fastio();
void fileio();
///////////////////////////////////////////////
/*
    유형: 그리디
    
    임의의 수 X에대해, X는 자신보다 작은 피보나치 수나
    두번째로 작은 피보나치수를 사용하여야 한다.
    피보나치수 1, 2, 3, 5, 8, 13, 21 가 있다고 하자.
    임의의수 x (x>=13 , x<21)에 대해 x는  13과 8의 합인 21 보다 작다.
    즉 x는 자신보다 작은 두 수의 합으로 나타낼 수 없다 ....(1)
    만약 둘 다 사용하지 않을경우, 1+2+3+5은 x의 최솟값인 13보다 작으므로 성립될수 없다 ...(2)
    만약 두번째 수를 사용한다면, 
    8은 5와 3으로 나타낼 수 있으므로 최소 갯수가 아니다. 
    따라서 최적 조건은 두칸씩 건너뛰는 8 + 3 + 1 = 12 < 13 이 되므로 성립될수 없다...(3)
    (1),(2),(3)에 의하여 최적의 해를 만드려면, 항상 n보다 같거나 작은 수를 써야한다.

*/
///////////////////////////////////////////////
int dp[101];
void solve() {
    int a;
    cin >> a;
    stack<int> s;
    while (a != 0) {
        RFOR(46, 0) {
            if (dp[i] <= a) {
                a -= dp[i];
                s.push(dp[i]);
                break;
            }
        }
    }
    while (s.size()) {
        cout << s.top() << " ";
        s.pop();
    }
}

int main() {
    fastio();
    // fileio();
    int T;
    T = 1;
    cin >> T;
    dp[1] = 1;
    dp[2] = 1;
    FOR(3, 1000001) {
        dp[i] = dp[i - 1] + dp[i - 2];
        if (dp[i] > 1e9) break;
    }
    for (int i = 1; i <= T; i++) {
        // cout << "Case #" << T << ": ";
        solve();
        cout << '\n';
    }
}

///////////////////////////////////////////////
void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileio() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}