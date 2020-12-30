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
    dp 동전

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int dp[50001];
vector<int> v;
int n;
const int INF = 1<<30;
int go(int k){
    if(k==0){
        return 0;
    }
    int&ret = dp[k];
    if(ret!=-1) return ret;
    ret = INF;
    for(int i=0; i < v.size(); i++){
        if(k >= v[i]){
            ret = min(ret,go(k-v[i])+1);
        }
    }
    return ret;
}


void solve(){
    cin >> n;
    for(int i=1; ;i++){
        if(i*i > 50000) break;
        v.push_back(i*i);
    }
    memset(dp,-1,sizeof(dp));

    cout << go(n);

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