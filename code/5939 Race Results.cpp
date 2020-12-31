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
    구현

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

struct Time{
    int h,m,s;
};

void solve(){
    int n;
    cin >> n;
    vector<Time> v;
    for(int i=0; i < n; i++){
        Time T;
        cin >> T.h  >> T.m >> T.s;
        v.push_back(T);
    }
    sort(all(v),[](Time a, Time b){
        if(a.h == b.h){
            if(a.m == b.m) return a.s < b.s;
            return a.m < b.m;
        }
        return a.h < b.h;
    });

    for(auto x : v){
        cout << x.h << " " << x.m << " " << x.s << '\n';
    }

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