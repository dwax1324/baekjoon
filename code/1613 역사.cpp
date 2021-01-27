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
    플로이드
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int INF = (1<<30)-1, MAX = 401;
int N,K,dist[MAX][MAX];

void solve(){
    cin >> N >> K;
    for(int i=0; i < N; i++){
        for(int j=0; j <N ;j ++){
            dist[i][j] = INF;
        }
    }

    for(int i=0; i < K; i++){
        int u,v; cin >> u >> v; u--;v--;
        dist[u][v] = 1;
    }

    for(int k=0; k < N; k++)
        for(int i=0; i < N; i++)
            for(int j=0; j < N; j++)
                dist[i][j] = min(dist[i][j]  ,dist[i][k]+dist[k][j]);

    int S; cin >> S;
    for(int i=0; i < S; i++){
        int u,v; cin >> u >> v; u--;v--;
        if(dist[u][v] == INF && dist[v][u] == INF) cout << 0;
        else if(dist[v][u] == INF) cout << -1;
        else if(dist[u][v] == INF) cout << 1;
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