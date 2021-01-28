#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.28 Thu
    comment: 
    dp
    dp(a,prev) =  길이가 a일고 이전 숫자가 prev일때의 숫자의 갯수
    
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int n; 
int cnt=0;
int dp[65][11];
int go(int a, int prev){
    if(a== n+1) {
        return 1;
    }
    int &ret =dp[a][prev];
    if(ret!=-1) return ret;
    ret=0;

    for(int i=prev; i <= 9; i++){
        ret += go(a+1,i);
    }
    return ret;
}


void solve(){
    int T; cin >> T; while(T--){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    cout << go(1,0) << '\n';
    }
}


int32_t main() {
    int t=1;
    fastio;
    // debug;
    {
        // cin >> t; 
        for(int i=1; i <= t; i++) solve();
    }
}