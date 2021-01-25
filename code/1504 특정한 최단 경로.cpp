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
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.25 Mon
    comment: 
    최단거리, 다익스트라

    방문배열빼주기
    A,B를 거쳐갈때 
    1->A->B->N
    1->B->A->N 이 있음
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int INF = 1<<30 , MAX_V = 801;
int N,E,A,B;
int vi[MAX_V],dist[MAX_V];
vector<pii> adj[MAX_V];

int dijkstra(int a, int b){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    fill(dist,dist+MAX_V,INF);
    memset(vi,0,sizeof(vi));
    dist[a] = 0;
    pq.push({dist[a],a});

    while(pq.size()){
        int curr = pq.top().o2;
        pq.pop();
        // if(pq.size() && vi[curr]){
        //     pq.pop();
        //     curr = pq.top().o2;
        // }
        // if(vi[curr]) break;
        // vi[curr]= true;

        for(auto &x : adj[curr]){
            int next= x.o1, w = x.o2;
            if(dist[next] > dist[curr] + w){
                dist[next] = dist[curr] +w;
                pq.push({dist[next],next});
            }
        }
    }
    return dist[b];
}


void solve(){
    int N,E; cin >> N >> E; N--;
    for(int i=0; i < E; i++){
        int u,v,w; cin >> u >> v >> w; u--;v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin >> A >> B; A--; B--;

    // path1 : 1 -> A -> B -> N
    // path2 : 1 -> B -> A- > N

    int path1_a = dijkstra(0,A) , path1_b = dijkstra(A,B) , path1_c = dijkstra(B,N);
    int path2_a = dijkstra(0,B) , path2_b = dijkstra(B,A) , path2_c = dijkstra(A,N);

    bool path1dead = path1_a == INF || path1_b == INF || path1_c == INF;
    bool path2dead = path2_a == INF || path2_b == INF || path2_c == INF;
    
    int path1val = path1_a + path1_b + path1_c;
    int path2val = path2_a + path2_b + path2_c;
    if(path1dead && path2dead){
        cout << -1;
    }else if(path1dead){
        cout << path2val;
    }else if (path2dead){
        cout << path1val;
    }else{
        cout << min(path1val,path2val);
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