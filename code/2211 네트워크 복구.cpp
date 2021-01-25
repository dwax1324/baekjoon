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
    2021.01.25 Mon
    comment: 
    다익스트라

    슈퍼컴퓨터 1번을 기준으로 간선을 연결시킨다.
    prev배열을 통한 역추적
    Spanning Tree 는 맞지만 MST아님

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX_V = 1001, INF = 1<<30;
int dist[MAX_V],vi[MAX_V],prev_[MAX_V], N,M;
vector<pii> adj[MAX_V];

void dijkstra(int s){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    fill(dist,dist+MAX_V,INF);
    dist[s] = 0;
    pq.push({0,s});
    while(pq.size()){
        int curr = pq.top().o2;
        while(pq.size() && vi[curr]){
            pq.pop();
            curr = pq.top().o2;
        }
        if(vi[curr]) break;
        vi[curr]= true;

        for(auto x : adj[curr]){
            int next = x.o1, w = x.o2;
            if(dist[next] > dist[curr]+ w){
                dist[next] = dist[curr]+w;
                prev_[next+1] = curr+1;
                pq.push({dist[next],next});
            }
        }
    }

}

void solve(){
    cin >> N>> M;
    for(int i=0; i < M; i++){
        int u,v,w; cin >> u >> v >> w; u--;v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dijkstra(0);
    
    int ans=0;
    for(int i=1; i<= N; i++){
        if(prev_[i] != 0) ans++;
    }

    cout << ans << '\n';
    for(int i=1; i<=N ; i++){
        if(prev_[i] !=0){
            cout << i << " " << prev_[i] << '\n';
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