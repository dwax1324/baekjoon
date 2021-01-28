#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef tuple<int,int> tii;
typedef tuple<int,int,int> tiii;
#define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.27 Wed
    comment: 
    
    이분탐색
    파를 치킨수만큼 등분했을때,
    가장 긴 길이를 찾으면 된다.
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


int S,C;
vector<int> v;

int go(int a){
    int ret=0;
    // if(a==0) return 0;
    for(int i=0; i < S;i++){
        ret += v[i]/a;
    }
    return ret;
}

void solve(){
    cin >> S >> C;
    int sum =0;
    for(int i=0; i < S; i++){
        int a; cin >> a;
        v.push_back(a);
        sum += v[i];
    }

    sort(all(v));
    int l=1, r=1000000000l;
    int mid,ans;
    while(l<=r){

        mid = (l+r)/2;
        int ret = go(mid);

        if(ret >= C){
            l = mid+1;
            ans=mid;
        }else{
            r = mid-1;
        }
        // cout << mid << " ";
    }

    int SUM = accumulate(all(v),0l);

    cout << SUM - ans * C << '\n';




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