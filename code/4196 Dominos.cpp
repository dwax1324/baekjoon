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

const int MAX = 100001;
int N,M,dfsn[MAX],finished[MAX],sn[MAX],SN,cnt;
vector<int> adj[MAX];
stack<int> stk;
int tarzan(int curr){

    stk.push(curr);
    dfsn[curr] = ++cnt;
    int res = dfsn[curr];

    for(auto next : adj[curr]){
        if(!dfsn[next]) res = min(res,tarzan(next));
        else if(!finished[next]) res = min(res,dfsn[next]);
    }

    if(dfsn[curr] == res){

        while(1){
            int t = stk.top(); stk.pop();
            finished[t] = true;
            sn[t] = SN;
            if(t== curr) break;
        }
        SN++;
    }
    return res;
}

void solve(){
    int T; cin >> T; while(T--){
        
        memset(adj,0,sizeof(adj));
        memset(finished,0,sizeof(finished));
        memset(sn,0,sizeof(sn));
        memset(dfsn,0,sizeof(dfsn));
        cnt=SN= 0;
        cin >> N>> M;
        for(int i=0; i < M ;i++){
            int u,v; cin >> u >> v; u--;v--;
            adj[u].push_back(v);
        }
        for(int i=0; i < N; i++){
            if(dfsn[i] ==0) tarzan(i);
        }

        int indegree[MAX] ={0};

        for(int i=0 ; i < N ; i++){
            for(auto j : adj[i])
                if(sn[i] != sn[j]) indegree[sn[j]]++;
        }
        int ans =0;
        for(int i=0; i < SN;i++){
            if(indegree[i] == 0) ans++;
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