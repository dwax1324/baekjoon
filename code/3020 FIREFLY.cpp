#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
void misc(int &t);
#define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.12.28
    comment: 
    석순 종유석을 따로 담는다.
    정렬한다.
    높이별로 순회하면서 그 높이의를 석순,종유석에서 이분탐색한다.
    답을낸다.

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

void solve(){
    int n,h;
    cin >> n >> h;
    vector<int> vlow,vhi;
    for(int i=0 ; i< n/2; i++){
        int a,b; cin >> a >> b;
        vlow.push_back(a);
        vhi.push_back(b);
    }
    sort(all(vlow));
    sort(all(vhi));
    // cout << '\n';
    // for(auto x : vhi) cout << x << " ";
    vector<int>hs(h,0);
    for(int i=0; i< h; i++){
        int vl2 = lower_bound(all(vlow),i+1)-vlow.begin();
        if(vlow[vl2]!=0){
            hs[i] += sz(vlow)-vl2;
        }
        int vh2 = lower_bound(all(vhi),h+1-(i+1))-vhi.begin();
        if(vhi[vh2]!=0){
            hs[i] += sz(vhi)-vh2;
        }
            

    }
    // cout << '\n';
    int MIN = *min_element(all(hs));
    int cnt=0;
    for(int i=0; i < h; i++){
        // cout << hs[i] << " ";
        if(hs[i] == MIN) cnt++;
    }

    cout << MIN << " " << cnt ;



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
    // debug;  
}