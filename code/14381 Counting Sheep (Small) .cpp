#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.14 Thu
    comment: 

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

void solve(){
    int t;cin >> t; for(int T=1; T <= t; T++){

    int n;
    cin >> n;
    cout << "Case #" << T << ": ";
    if(n==0) cout << "INSOMNIA\n";
    else{
        int vi[10];
        memset(vi,0,sizeof(vi));
        int z=1, rn = n;
        for(;;z++){
            int temp = n;
            while(temp){
                vi[temp%10] = 1;
                temp/=10;
            }

            int cnt=0;
            for(int i=0; i<=9; i++){
                if(vi[i]) cnt++;
            }
            if(cnt==10) break;
            n = rn*z;
        }
        cout << n << '\n';
    }

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