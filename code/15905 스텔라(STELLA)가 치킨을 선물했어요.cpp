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
    2021.01.28 Thu
    comment: 
    정렬문제
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


bool cmp(pii a, pii b){
    if(a.o1 == b.o1) return a.o2 < b.o2;
    return a.o1 > b.o1;
}

void solve(){
    int n;
    cin >> n;
    vector<pii> v(n);
    for(int i=0; i < n; i++){
        cin >> v[i].o1 >> v[i].o2;
    }

    sort(all(v),cmp);
    int ans=0;
    for(int i=5; i < n; i++){
        if(v[i].o1 == v[4].o1) ans++;
    }
    cout << ans;

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