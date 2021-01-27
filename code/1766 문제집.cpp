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
    위상정렬
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX = 32001;
int N,M,res[MAX],indegree[MAX];
vector<int> adj[MAX];

void solve(){
    cin >> N >> M;
    for(int i=0; i < M; i++){
        int a,b; cin >> a >> b; a--;b--;
        indegree[b]++;
        adj[a].push_back(b);
    }
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0; i < N; i++){
        if(indegree[i] == 0) q.push(i);
    }

    for(int i=0; i < N; i++){
        if(q.size() == 0){
            cout << -1; exit(0);
        }
        
        int curr= q.top();
        q.pop();
        res[i] = curr;
        for(auto next : adj[curr]){
            indegree[next]--;
            if(indegree[next] == 0) q.push(next);
        }
    }

    for(int i=0; i < N; i++){
        cout << res[i]+1 << " ";
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