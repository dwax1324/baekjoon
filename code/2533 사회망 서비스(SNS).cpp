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
    2021.01.22 Fri
    comment: 

    트리위의 dp

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

#define MAX 1000001

vector<int> adj[MAX], child[MAX];
bool vi[MAX];
int n, dp[MAX][2];

void dfs(int cur){
    vi[cur] = true;
    for(auto next : adj[cur]){
        if(!vi[next]){
            child[cur].push_back(next);
            dfs(next);
        }
    }
}


int SNS(int cur, bool pe){
    int &ret = dp[cur][pe];
    if(ret != -1) return ret;

    int notPick = 1<<30, pick =1;

    for(auto next : child[cur])
        pick += SNS(next, true);

    if(pe){

        notPick =0;
        for(auto next : child[cur])
            notPick += SNS(next, false);

    }
    ret= min(notPick, pick);

    return ret;
}



void solve(){
    cin >> n;
    for(int i=0; i < n-1; i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    
    memset(dp,-1,sizeof(dp));

    cout << SNS(0,true);

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