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
const int MAX=1001;
int N,M,here[MAX],there[MAX];
vector<int> adj[MAX];
bool vi[MAX];


bool dfs(int me){
    vi[me] = true;

    for(auto you : adj[me]){
        if(there[you] == -1 || (!vi[there[you]] && dfs(there[you]))){
            here[me] = you;
            there[you] =me;
            return true;
        }
    }
    return false;
}


void solve(){
    int T; cin>> T; while(T--){

    memset(adj,0,sizeof(adj));
    cin >> N>> M;
    for(int i= 0 ; i< M; i++){
        int a,b;
        cin >> a >> b; a--;b--;
        for(int j=a; j <= b; j++){
            adj[i].push_back(j);
        }
    }
    memset(here,-1,sizeof(here));
    memset(there,-1,sizeof(there));

    int ans =0;
    for(int i=0; i <M ;i++){
        if(here[i] == -1){
            memset(vi,0,sizeof(vi));
            if(dfs(i)) ans++;
        }
    }
    cout << ans << '\n';

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