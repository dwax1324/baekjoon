#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
void misc(int32_t &t);
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.12.29
    comment: 
    [i번째 price까지만으로] [ n개의 카드를 살때]의 값
    난 멍청이다~

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
int arr[1001];
int dp[1001][1001];
int n;

const int INF = 1<<30;
int go(int num , int pi){
    // printf("num is %d , pi is : %d\n",num,pi);
    if(num == n){
        return 0;
    }
    if(num > n) return INF;
    int &ret = dp[num][pi];
    if(ret != -1) return ret;
    ret = go(num+1, pi) + arr[pi];
    for(int i=2; i<= n; i++){
        ret = min(ret, go(num+i,pi) + arr[i]);
    }
    

    return ret;
}

void solve(){
    cin >> n;
    for(int i=1; i <= n; i++){
        cin >> arr[i];
    }
    memset(dp,-1,sizeof(dp));

    cout << go(0,1);

}


int32_t main() {
    int32_t T = 1;
    misc(T);
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        // cout << "Data Set "<< i << ":\n";
        // cout << "case #" << i << ": ";
        solve();
    }
}

void misc(int32_t &T){
    fastio;
 //   debug;  
}