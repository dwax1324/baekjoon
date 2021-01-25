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
    벨만포드
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX = 100, INF = 1e9*2 +1;
int N,M;

void solve(){
    
    cin >> N>> M;

    // 벨만포드용 / bfs용 인접리스트를 만든다.
    vector<pii> adj[MAX];
    vector<int> rAdj[MAX];

    // 방문배열을 만든다/
    bool reachable[MAX] = {false,};
    for(int i=0; i < M; i++){
        int u,v,w; cin >> u >> v >> w; u--;v--;
        // 간선치를 역으로 넣는다.
        adj[u].push_back({v,-w});
        rAdj[v].push_back(u);
    }
    // 끝점에서부터 bfs를 돌린다.
    reachable[N-1] = true;
    queue<int> Q;
    Q.push(N-1);
    while(Q.size()){
        int curr = Q.front();
        Q.pop();
        for(auto next : rAdj[curr]){
            if(!reachable[next]){

                // reachable= true면 끝점에서부터 다다를수 있는 정점이다.
                reachable[next] = true;
                Q.push(next);
            }
        }
    }
    
    // 벨만포드알고리즘을 돌린다.
    int dist[MAX], prev[MAX];
    fill(dist,dist+N,INF);
    fill(prev,prev+N,-1);
    dist[0] =0;
    for(int i=0; i < N; i++){
        for(int curr=0; curr < N; curr++){
            for(auto x : adj[curr]){
                int next = x.o1, w = dist[curr] + x.o2;
                if(dist[curr] != INF && dist[next] > w){
                    // 만약 음수사이클이면서
                    // 끝점으로까지 방문가능한 곳이면 -1을 출력한다.
                    if(i == N-1 && reachable[next]){
                        cout << -1;
                        return;
                    }   

                    dist[next] = w;
                    prev[next] = curr;
                }
            }
        }
    }
    // 역추적 배열을 출력한다.
    if(dist[N-1] == INF) cout << -1;
    else{
        vector<int> path;
        for(int i= N-1; i!= 0 ; i= prev[i])
            path.push_back(i+1);
        path.push_back(1);

        for(int i= path.size()-1; i >=0; i--){
            cout << path[i] << ' ';
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