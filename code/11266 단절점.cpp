#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef tuple<int,int> tii;
typedef tuple<int,int,int> tiii;
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.27 Wed
    comment: 
    
    BCC, 단절점
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX =10001;
int V,E,cnt,root,dfsn[MAX];
vector<int>adj[MAX];
set<int>cut;

int DFS(int curr){

    dfsn[curr] = ++cnt;
    int res = dfsn[curr], child =0;
    for(int next : adj[curr]){
        if(dfsn[next] !=0) res = min(res,dfsn[next]);
        else{
            int temp = DFS(next);
            res = min(res,temp);
            if(curr != root && temp >= dfsn[curr]) cut.insert(curr);
            child++;
        }
    }
    if(curr == root && child > 1) cut.insert(curr);
    return res;
}



void solve(){
    cin >> V >>E;
    for(int i=0; i < E; i++){
        int u,v; cin >> u >> v; u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i < V;i++){
        if(dfsn[i] == 0){
            root =i;
            DFS(i);
        }
    }
    cout << cut.size() << '\n';
    for(int x : cut) cout << x +1 << '\n';


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