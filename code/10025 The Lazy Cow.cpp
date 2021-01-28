#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
#define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.28 Thu
    comment: 
    투포인터, 부분합
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int N,K,g,x;
int coord[1000001];

void solve(){
    cin >> N>> K;
    for(int i=0; i < N ;i++){
        cin >> g >> x;
        coord[x] = g;
    }

    int l=0,r=0,sum=0,len=0;


    int ans=0;
    while(1){
        len = r-l;
        if(len > 2*K ){
            sum -= coord[l];
            l++;
        }else{
            if(r == 1000000) break;
            sum += coord[r];
            r++;
        }
        ans= max(ans,sum);
        // cout << sum << " "; 
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