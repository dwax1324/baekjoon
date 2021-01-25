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
    2021.01.26 Tue
    comment: 
    벨만포드
    음수사이클만 확인하면됨
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX= 501, INF = 1l<<62;
int N ,M, W, vi[MAX], dist[MAX];
vector<pii> adj[MAX];


bool bellman_ford(int S){
    dist[S] =0;
    vi[S]= true;
    bool cycle = 0;
    for(int i=0; i < N; i++){
        for(int curr= 0; curr < N; curr++){

            for(auto x : adj[curr]){
                int next = x.o1, w = x.o2 +  dist[curr];
                if(dist[curr] != INF && dist[next] > w){
                    vi[next] = true;
                    dist[next] = w;
                    if(i == N-1) cycle = true;
                }
            }

        }
    }
    return cycle;

}



void solve(){

    int T; cin >> T; while(T--){

    memset(vi,0,sizeof(vi));
    fill(dist,dist+MAX,INF);
    memset(adj,0,sizeof(adj));
    cin >> N >> M >> W;
    for(int i=0; i < M; i++){
        int u,v,w; cin >> u >> v >> w; u--;v--;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    for(int i=0; i < W ; i++){
        int u,v,w; cin >> u >>  v >> w; u--;v--;
        adj[u].push_back({v,-w});
    }

    bool ans=0;
    for(int i=0; i < N; i++){
        if(!vi[i]){
            if(bellman_ford(i)){
                ans=1;
            }
        }
    }
    if(ans) cout << "YES\n";
    else cout << "NO\n";

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