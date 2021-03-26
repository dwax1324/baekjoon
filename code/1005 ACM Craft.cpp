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
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾
    2021.01.26 Tue
    comment: 
    위상정렬
    감격의 1005번
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX = 1001;
int N,K,D,res[MAX],time_[MAX],indegree[MAX];
vector<int> adj[MAX];

void solve(){

    int T; cin >> T; while(T--){
    
    memset(res,0,sizeof(res));
    memset(time_,0,sizeof(time_));
    memset(indegree,0,sizeof(indegree));
    memset(adj,0,sizeof(adj));
    cin >> N>> K;
    for(int i=0; i < N; i++){
        cin >> time_[i];
    }

    for(int i=0; i < K; i++){
        int a,b; cin >> a >> b; a--;b--;
        adj[a].push_back(b);
        indegree[b]++;
    }
    cin >> D;
    queue<int> q;
    for(int i=0; i < N; i++){
        if(indegree[i] ==0 ) {
            q.push(i);
            res[i] = time_[i];
        }
    }


    for(int i=0; i < N; i++){
        // if(q.size() == 0){
        //     cout << -1; exit(0);
        // }
        int curr= q.front();
        q.pop();
        for(auto next : adj[curr]){
            res[next] = max(res[next], res[curr] + time_[next]);
            indegree[next]--;
            if(indegree[next]==0) q.push(next);
        }
    }

    cout << res[--D] << '\n';
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