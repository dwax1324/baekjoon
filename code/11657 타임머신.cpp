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
    벨만포드
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int INF = 1LL<<62;



void solve(){
    int N, M,dist[501];
    cin >> N>> M;
    vector<pii> adj[501];
    for(int i=0; i < M; i++){
        int u,v,w; cin >> u >> v >> w; u--;v--;
        adj[u].push_back({v,w});
    }
    bool negativeCycle = false;
    fill(dist,dist+N,INF);
    dist[0] = 0;
    for(int i=0; i < N; i++){
        for(int j=0; j < N ;j++){
            for(auto x : adj[j]){
                int next = x.o1, w = x.o2;
                if(dist[j] != INF && dist[next] > dist[j] + w){
                    dist[next] = dist[j] + w;
                    if(i == N-1) negativeCycle = true;
                }
            }
        }
    }
    if(negativeCycle) cout << -1;
    else {
        for(int i=1; i<N; i++){
            dist[i] != INF ? cout << dist[i] << '\n' : cout << -1 << '\n';
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