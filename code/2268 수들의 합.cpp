#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define pii pair<int,int>
#define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.23 Sun
    comment: 
    세그트리 
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX = 1000001;
int seg[4*MAX],arr[MAX],N,M;

struct SegTree{
    int query(int l, int r, int node, int nodeL, int nodeR){
        if(l > nodeR || r < nodeL) return 0;
        if(l <= nodeL && r >= nodeR) return seg[node];
        int mid= (nodeL+nodeR)/2;
        return query(l,r,node*2,nodeL,mid) + query(l,r,node*2+1,mid+1,nodeR);
    }

    int update(int ti, int nv, int node, int nodeL , int nodeR){
        if(ti < nodeL  || ti > nodeR) return seg[node];
        if(nodeL == nodeR) return seg[node] = nv;
        int mid = (nodeL +nodeR)/2;
        return seg[node] = update(ti,nv,node*2,nodeL,mid) + update(ti,nv,node*2+1,mid+1,nodeR);
    }

};

void solve(){
    cin >> N >> M;
    SegTree ST;
    for(int i=0; i < M; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a == 0 && b>c) swap(b,c);
        if(a == 1){
            ST.update(b,c,1,1,N);
        }else{
            cout << ST.query(b,c,1,1,N) << '\n';
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