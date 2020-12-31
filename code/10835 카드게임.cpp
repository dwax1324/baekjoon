#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int int64_t
void misc(int32_t &t);
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.12.31
    comment: 
    dp
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int ldummy[2001],rdummy[2001];
int dp[2001][2001];
int go (int chooseL, int chooseR){
    if(chooseL < 0 || chooseR < 0){
        return 0;
    }

    int &ret= dp[chooseL][chooseR];
    // cout << ret << '\n';
    if(ret!= -1) return ret;
    
    ret = go(chooseL-1, chooseR-1);
    ret = max(ret,go(chooseL -1, chooseR));

    if(rdummy[chooseR] < ldummy[chooseL]){
        // printf("chooseL : %d , chooseR : %d , Lval : %d , Rval : %d\n",chooseL, chooseR , ldummy[chooseL],rdummy[chooseR]);
        ret = max(ret,go(chooseL,chooseR-1) + rdummy[chooseR]);
    }

    return ret;


}

void solve(){
    int n;
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> ldummy[i];
    }
    for(int i=0; i < n; i++){
        cin >> rdummy[i];
    }
    reverse(ldummy,ldummy+n);
    reverse(rdummy,rdummy+n);
    memset(dp,-1,sizeof(dp));

    cout << go(n-1,n-1);

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