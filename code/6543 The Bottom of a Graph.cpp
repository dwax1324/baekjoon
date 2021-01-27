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
    SCC의 outdegree세는 문제
    지문은 이해 못하겟따.
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX =5001;
int N,M,SN,sn[MAX],cnt,finished[MAX],dfsn[MAX];
vector<int> adj[MAX];
stack <int> stk;

int tarzan(int curr){

    stk.push(curr);
    int ret = dfsn[curr] = ++cnt;

    for(auto next : adj[curr]){
        if(dfsn[next] ==0) ret= min(ret,tarzan(next));
        else if(finished[next] ==0) ret = min(ret,dfsn[next]);
    }

    if(ret == dfsn[curr]){
        while(1){
            int t = stk.top(); stk.pop();
            sn[t] = SN;
            finished[t] = true;
            if(t == curr) break;
        }
        SN++;
    }
    return ret;
}


void solve(){
    while(1){
        SN=cnt=0;
        cin >> N;
        if(N ==0) break;
        for(int i=0; i < N; i++){
            adj[i].clear();
            dfsn[i] = finished[i] = 0;
        }
        cin >> M;
        for(int i=0; i < M; i++){
            int u,v; cin >> u >> v; u--;v--;
            adj[u].push_back(v);
        }

        for(int i=0; i < N; i++){
            if(dfsn[i] == 0) tarzan(i);
        }
        int indegree[MAX] = {0};

        for(int i=0; i < N; i++){
            for(auto j : adj[i]){
                if(sn[i] != sn[j]) indegree[sn[i]]++;
            }
        }

        for(int i =0; i < N; i++){
            if(indegree[sn[i]] == 0 ) cout << i+1  << " ";
        }
        cout << '\n';


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