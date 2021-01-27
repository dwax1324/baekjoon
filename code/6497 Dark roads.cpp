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
    2021.01.26 Tue
    comment: 
    MST 

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


const int MAX = 200001;
int N,M,p[MAX];

struct UnionFind{
    
    int find(int a){
        if(p[a] < 0 ) return a;
        return p[a] = find(p[a]);
    }

    bool union_(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b ) return false;
        p[b] =a;
        return true;
    }
};


void solve(){
    while(1){
    
    cin >> N >> M;
    if(!N && !M) break;
    memset(p,-1,sizeof(p));
    vector<tiii> edges(M);
    int ans=0;
    for(int i=0; i < M ; i++){
        int u,v,w; cin >> u >> v >> w;
        edges[i] = {w,u,v};
        ans += w;
    }
    sort(all(edges));

    int cnt=0;
    UnionFind UF;
    for(auto i : edges){
        int u,v,w;
        tie(w,u,v) = i;
        if(UF.find(u) != UF.find(v)){
            UF.union_(u,v);
            ans -= w;
            if(++cnt == N-1) break;
        }
    }        

    cout << ans << '\n';

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