#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.08 Fri
    comment: 
    dfs

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


int vi[1001];
int senbai[1001];
int ans[1001];
int dfs(int x){
    if(vi[x]) return 0;
    vi[x] = true;
    int ret= 1;
    ret += dfs(senbai[x]);
    return ret;
}


void solve(){
    int n;
    cin >> n;
    for(int i=0; i <n ; i++){
        int a; cin >> a; a--;
        senbai[i] = a;
    }

    int MAX=0;
    for(int i=0; i < n; i++){
        memset(vi,0,sizeof(vi));
        ans[i] = dfs(i);
        MAX = max(ans[i],MAX);
    }

    
    int ret=0;
    for(int i=0; i < n; i++){
        if(MAX == ans[i]){
            ret = i+1;
            break;
        }
    }
    cout << ret;
    

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