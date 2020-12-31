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
    2020.12.31
    comment: 
    2020 마지막날 
    dp~

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
int c,n;
struct Info{
    int price,customer;
};
vector<Info> v;

int dp[21][1001];
const int INF = 1<<30;
int go(int idx, int custom){
    if(idx >= n) return INF;
    if(custom >= c){
        return 0;
    }
    int&ret= dp[idx][custom];
    if(ret!=-1)return ret;
    ret = go(idx +1, custom);
    // printf("%d\n",v[idx].customer);
    ret = min(ret, go(idx,custom + v[idx].customer) + v[idx].price);

    return ret;

}

void solve(){
    cin >> c >> n;
    v.resize(n);
    for(int i=0; i < n; i++){
        cin >> v[i].price >> v[i].customer;
    }
    memset(dp,-1,sizeof(dp));
    cout << go(0,0);


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