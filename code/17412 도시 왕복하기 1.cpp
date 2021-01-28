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
    2021.01.28 Thu
    comment: 
    Maximum Flow
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX_N = 401;
const int MAX_V = MAX_N*2 +2;
int N,P;

struct EdmondsKarp{
    struct Edge{
        int to,cap,flow;
        Edge* reverseEdge;
        Edge(int to1 = -1, int cap1 = 0): to(to1), cap(cap1), flow(0), reverseEdge(nullptr){}
        int spare(){
            return cap-flow;
        }
        void addFlow(int flow1){
            flow += flow1;
            reverseEdge->flow -= flow1;
        }
    };
    vector<Edge*> adj[MAX_V];

    void addEdge(int u, int v, int cap){
        Edge* e1 = new Edge(v,cap), *e2 = new Edge(u,0);
        e1 -> reverseEdge = e2;
        e2 -> reverseEdge = e1;
        adj[u].push_back(e1);
        adj[v].push_back(e2);
    }

    int MaximumFlow(int S, int E){
        int ret= 0;
        while(1){
            int prev[MAX_V];
            memset(prev,-1,sizeof(prev));
            Edge*path[MAX_V];
            queue<int> Q;
            Q.push(S);

            while(Q.size() && prev[E] == -1){
                int curr = Q.front(); Q.pop();
                for(auto *e : adj[curr]){
                    int next = e->to;
                    if(e->spare() > 0 && prev[next] ==-1){
                        Q.push(next);
                        prev[next] =curr;
                        path[next] =e;
                        if (next == E) break;
                    }
                }
            }
            if(prev[E] == -1)break;
            int flow = 1<<30;
            for(int i= E; i!= S; i=prev[i])
                flow = min(flow,path[i]->spare());
            for(int i= E; i!= S; i=prev[i])
                path[i] -> addFlow(flow);
            
            ret += flow;
        }
        return ret;
    }
};

void solve(){
    cin >> N>> P;
    EdmondsKarp EK;

    for(int i=0; i < P; i++){
        int a, b; cin >> a >> b;
        EK.addEdge(a,b,1);
    }

    cout << EK.MaximumFlow(1,2);

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