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
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

bool isPrime(int a){
    if( a<=1) return false;
    for(int i=2; i*i<= a; i++){
        if(a%i==0) return false;
    }
    return true;
}


void solve(){
    vector<int> v;
    for(int i=2; i< 1000; i++){
        if(isPrime(i)) v.push_back(i);
    }
    int n; cin >> n; while(n--){

        int a; cin >> a;

        int sz= v.size();
        for(int i=0; i <sz; i++){
            for(int j=0; j <sz; j++){
                for(int k=0; k < sz; k++){
                    if(v[i] + v[j] + v[k] == a) {
                        cout << v[i] << " " << v[j] << " " << v[k] << '\n';
                        goto bol;
                    }
                }
            }
        }
        bol:
            continue;

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