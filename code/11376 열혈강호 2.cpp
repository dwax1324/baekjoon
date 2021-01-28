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
    bipartite matching
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX =1001 *2;
int N,M,here[MAX],there[MAX];
vector<int> adj[MAX];
bool vi[MAX];

bool dfs(int me){
    vi[me] = true;

    for(auto you : adj[me]){
        int cand = there[you];
        if(cand == -1 || (!vi[cand] && dfs(cand))){
            here[me] = you;
            there[you] = me;
            return true;
        }
    }
    return false;
}


void solve(){
    cin >> N>> M;
    for(int i=0; i < N; i++){
        int t;cin >> t; while(t--){
            int a; cin >> a; a--;
            adj[i*2].push_back(a);
            adj[i*2+1].push_back(a);
        }
    }
    
    memset(here,-1,sizeof(here));
    memset(there,-1,sizeof(there));

    int ans=0;
    for(int i=0; i < N*2+2; i++){
        if(here[i] == -1){
            memset(vi,0,sizeof(vi));
            ans += dfs(i);
        }
    }
    cout << ans;



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