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
    2020.12.30
    comment: 
    dp lis

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


int n;
int arr[1001];
int dp[1001];
int go(int start){

    int &ret = dp[start+1];
    if(ret!= -1) return ret;
    ret = 1;
    for(int next=start+1; next< n; next++){
        if(start == -1 || arr[next] > arr[start]){
             ret = max(ret,go(next) +1);
        }
    }
    return ret;
}

void solve(){
    cin >> n;
    for(int i=0; i < n ;i ++){
        cin >> arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << go(-1)-1;

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