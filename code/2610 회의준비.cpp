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
    플로이드 + 컴포넌트추출

    
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int INF=(1<<30)-1,MAX = 101;
int N,M,dist[MAX][MAX],vi[MAX];
vector<int> adj[MAX], temp;
vector<vector<int>> components;


void dfs(int cur){
    vi[cur] = true;
    temp.push_back(cur);
    for(auto next : adj[cur]){
        if(!vi[next]) {
            dfs(next);
        }
    }
    return;
}

void solve(){
    cin >> N>> M;
    for(int i=0; i < N; i++)
        for(int j=0; j <N ;j++)
            dist[i][j] = (i==j ? 0 : INF);

    for(int i=0; i < M ;i++){
        int u,v; cin >> u >> v; u--;v--;
        dist[u][v] = dist[v][u] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //컴포넌트 추출
    
    for(int i=0; i < N; i++){
        if(!vi[i]){
            temp={};
            dfs(i);
            components.push_back(temp);
        }
    }
    // 플로이드

    for(int k=0; k < N; k++)
        for(int i=0; i < N; i++)
            for(int j=0; j< N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    
    // 모든 컴포넌트에 대해서
    vector<int> ans;
    for(int i=0; i < components.size() ;i++){
        // 각 컴포넌트에 대해서
        int res = INF+1,tempans = INF;
        for(int j=0; j < components[i].size(); j++){
            int MAX = -INF;
            int u,v;
            for(int k= 0; k < components[i].size(); k++){
                u = components[i][j], v = components[i][k];
                if(u==v) continue;
                MAX = max(MAX,dist[u][v]);
            }
            // cout << MAX << " " << u+1 << '\n';
            if(res > MAX){
                res = MAX;
                // cout << res << " " << u+1 << '\n';
                tempans = u+1;
            }
        }
        // cout << '\n';
        ans.push_back(tempans);
    }

    cout << ans.size() << '\n';
    sort(all(ans));
    for(auto x : ans) {
        cout << x << '\n';
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