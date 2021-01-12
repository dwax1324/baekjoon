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

    구현

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

void solve(){
    int n;
    while(1){
    cin >> n;
    if(!n) return;
    vector<int> v(1000);
    v[0] = n;
    for(int i=1; v[i-1] != 1;i++){
        if(v[i-1]%2==1)
            v[i] = 3*v[i-1]+1;
        if(v[i-1]%2==0)
            v[i] = v[i-1]/2;
    }
    int ans=0;
    for(auto x : v)
        ans = max(x,ans);
    cout << ans << '\n';
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