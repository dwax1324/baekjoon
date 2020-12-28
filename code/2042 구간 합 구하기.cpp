#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
void misc(int &t);
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.12.27
    comment: 

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
#define int int64_t
// using long long as default, should consider TLE or RTE of it


int n,m,k;
const int MAX = 1e6+2;
int seg[MAX*4];
int arr[MAX];

struct Segtree{
    int query(int l, int r, int node ,int nodeL, int nodeR){
        if( nodeL > r  || nodeR <   l) return 0;
        if( l <= nodeL && nodeR <= r) return seg[node];
        int mid = (nodeL + nodeR) /2;
        return query(l,r,node*2,nodeL,mid)+ query(l,r,node*2+1,mid+1,nodeR);
    }

    int update(int idx, int val, int node, int nodeL, int nodeR){
        if( idx < nodeL || nodeR < idx) return seg[node];
        if( nodeL == nodeR) return seg[node] = val;
        int mid = (nodeL + nodeR) /2;
        return seg[node] = update(idx,val,node*2,nodeL,mid)+ update(idx,val,node*2+1,mid+1,nodeR);

    }

    int construct(int l, int r, int node){
        if (l == r) return seg[node] = arr[l];
        int mid= (l+r) /2;
        return seg[node] = construct(l, mid, node*2) + construct(mid+1,r,node*2+1);
    
    }
};



void solve(){
    cin >> n >> m >> k;
    Segtree tree;  
    for(int i=1; i <= n; i++){
        int a;
        cin >> a;
        arr[i] = a;
    }
    tree.construct(1,n,1);
    for(int i=1; i<= m+k; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if(a==1){
            tree.update(b,c,1,1,n);            
        }else if(a==2){
            cout << tree.query(b,c,1,1,n) << '\n';
        }
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