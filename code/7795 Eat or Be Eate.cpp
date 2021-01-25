#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.25 Mon
    comment: 
    정렬,투포인터
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


void solve(){
    int t; cin >> t; while(t--){
        int n,m; cin >> n >> m;
        vector<int> va(n),vb(m);
        for(int i=0; i < n ; i++){
            cin >> va[i];
        }
        for(int i=0 ; i< m; i++){
            cin >> vb[i];
        }
        sort(rall(va)); sort(rall(vb));
        int ans=0;
        for(int i=0; i < va.size(); i++){
            for(int j=0; j < vb.size(); j++){
                if(va[i] > vb[j]) {
                    ans += vb.size()-j;
                    break;
                }
            }
        }
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