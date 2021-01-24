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

const int MAX =100001;
int seg[MAX*4],arr[MAX],N,Q;

struct SegTree{

    int init(int node, int nodeL, int nodeR){
        if(nodeL == nodeR) return seg[node] = arr[nodeL];
        int mid = (nodeL+nodeR)/2;
        return seg[node] = init(node*2, nodeL,mid) + init(node*2+1, mid+1,nodeR);
    }

    int query(int l, int r, int node, int nodeL, int nodeR){
        if(l > nodeR || r < nodeL) return 0;
        if(l <=nodeL && r >= nodeR) return seg[node];
        int mid = (nodeL+nodeR)/2;
        return query(l,r,node*2,nodeL,mid) + query(l,r,node*2+1,mid+1,nodeR);
    }

    int update(int ti, int nv, int node, int nodeL, int nodeR){
        if(ti < nodeL || ti > nodeR) return seg[node];
        if(nodeL == nodeR) return seg[node] = nv;
        int mid = (nodeL+nodeR)/2;
        return seg[node] = update(ti,nv,node*2,nodeL,mid) + update(ti,nv,node*2+1,mid+1,nodeR);
    }

};


void solve(){
    cin >> N >> Q;
    for(int i=1 ; i<= N; i++){
        cin >> arr[i];
    }
    SegTree ST;
    ST.init(1,1,N);

    for(int i=0; i< Q; i++){
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        if(x > y) {
            swap(x,y);
        }
        cout << ST.query(x,y,1,1,N) << '\n';
        ST.update(a,b,1,1,N);
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