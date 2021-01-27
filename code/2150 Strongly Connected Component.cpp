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
    2021.01.27 Wed
    comment: 
    강한결합요소 SCC
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX= 10001;
int N,M,cnt=1,SN,sn[MAX],dfsn[MAX],finished[MAX];
vector<vector<int>> SCC;
vector<int> adj[MAX];
stack<int> stk;

int dfs(int curr){
    dfsn[curr] = cnt++;
    stk.push(curr);

    int res = dfsn[curr];

    for(auto next  : adj[curr]){
        if(dfsn[next] ==0) res = min(res, dfs(next));
        else if(finished[next]==0) res = min(res,dfsn[next]);
    }

    if(res == dfsn[curr]){
        vector<int> scc;
        while(1){
            int t = stk.top(); stk.pop();
            scc.push_back(t);
            sn[t] = SN;
            finished[t] = true;
            if(t==curr) break;
        }
        sort(all(scc));
        SCC.push_back(scc);
        SN++;
    }
    return res;
}


void solve(){
    cin >> N>> M;
    for(int i=0; i < M; i++){
        int u,v; cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
    }

    for(int i=0; i < N; i++){
        if(dfsn[i] == 0) dfs(i);
    }

    sort(all(SCC));
    cout << SCC.size() << '\n';
    for(auto scc : SCC){
        for(auto node : scc){
            cout << node +1 << " ";
        }
        cout << "-1\n";
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