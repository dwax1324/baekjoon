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
    dp[다음 가야할 곳][ 왼쪽 열려있는 문] [오르쪽 열려있는 문]
    
    go(opidx,l,r) = min(l + abs(next - leftidx), r + abs(next - rightidx);

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


int dp[21][21][21];
vector<int> vops;
int ops;


int go(int opidx, int l, int r){
    if(opidx == ops){
        return 0;
    }

    int &ret = dp[opidx][l][r];
    if(ret!= -1) return ret;
    
    ret = go(opidx+1,vops[opidx], r) + abs(vops[opidx] - l);
    ret = min(ret,go(opidx+1,l,vops[opidx]) + abs(vops[opidx]-r));

    return ret;
}

void solve(){
    int n;
    cin >> n;
    int l,r;
    cin >> l >> r;
    cin >> ops;
    for(int i=0; i < ops; i++){
        int a;
        cin >> a;
        vops.push_back(a);
    }
    memset(dp,-1,sizeof(dp));
    cout << go(0,l,r);
    

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