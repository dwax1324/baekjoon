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
    구현 정렬

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


struct info{
    int a,b,idx;
};

void solve(){
    int n,k;
    cin >> n >> k;
    vector<info> v;
    for(int i=0; i < n; i++){
        info Info;
        cin >> Info.a >> Info.b;
        Info.idx = i+1;
        v.push_back(Info);
    }

    sort(all(v),[](info a, info b){
        return a.a > b.a;
    });


    int MAX = 0;
    for(int i=0; i < k ;i++){
        MAX = max(MAX,v[i].b);
    }

    for(int i=0; i < k ;i++){
        if(v[i].b == MAX) cout << v[i].idx;
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