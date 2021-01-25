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
#define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.25 Mon
    comment: 
    다익스트라
    
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


const int MAX_N = 100001, INF = 1LL<<62;
int N,M,D,E, vi[MAX_N], height[MAX_N];
vector<pii> adj[MAX_N];
int dist[MAX_N];

int* dijkstra(int u){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    memset(vi,0,sizeof(vi));
    fill(dist,dist+MAX_N,INF);
    dist[u] =0;
    pq.push({0,u});
    while(pq.size()){
        int curr = pq.top().o2;
        while(pq.size() && vi[curr]){
            pq.pop();
            curr=  pq.top().o2;
        }
        if(vi[curr]) break;
        vi[curr] = true;

        for(auto x : adj[curr]){
            int next = x.o1, w = x.o2;
            if(height[curr] < height[next] && dist[next] > dist[curr] + w){
                dist[next] = dist[curr] +w;
                pq.push({dist[next],next});
            }
        }
    }
    int *ret = (int*)malloc(sizeof(int)*N);
    for(int i=0; i < N; i++){
        ret[i] = dist[i];
    }
    return ret;
}

void solve(){
    cin >> N >> M >> D >> E;
    for(int i=0; i < N; i++){
        cin >> height[i];
    }
    for(int i=0; i < M; i++){
        int u,v,w; cin >> u >> v >> w;u--;v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int *arr = dijkstra(0);
    int *arr2 = dijkstra(N-1);

    int ans=-(1LL<<62);
    for(int i=0; i < N; i++){
        if(arr[i] == INF || arr2[i] == INF) continue;
        ans = max(ans,(E*height[i] - D*(arr[i]+arr2[i])));
    }
    (ans == -(1LL<<62) )? cout << "Impossible\n" : cout << ans << '\n';

    free(arr);
    free(arr2);

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