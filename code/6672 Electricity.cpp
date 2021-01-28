#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.27 Wed
    comment: 
    BBC 이중연결요소

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX= 100001;
int N,M,dfsn[MAX],cnt,root,ans;
vector<int> adj[MAX];

int dfs(int curr){

    int ret = dfsn[curr] = ++cnt, child =0, cpn=0;
    for(auto next : adj[curr]){
        if(dfsn[next] != 0) ret = min(ret, dfsn[next]);
        else{
            int temp = dfs(next);
            ret = min(ret,temp);
            if(root != curr && temp >= dfsn[curr]) cpn++;
            child++;
        }
    }
    if(root != curr) ans = max(ans,cpn);
    else ans = max(ans,child-1);
    return ret;
}


void solve(){
    while(1){
    memset(dfsn,0,sizeof(dfsn));
    memset(adj,0,sizeof(adj));
    cin >> N>> M;
    if(!N && !M) break;
    for(int i=0; i < M ;i++){
        int u,v; cin>> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans=-1;
    int cpn=0;
    for(int i=0; i <N ;i++){
        if(dfsn[i] == 0){
            root =i;
            cpn++;            
            dfs(i);
        }
    }
    cout << ans+cpn << '\n';
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