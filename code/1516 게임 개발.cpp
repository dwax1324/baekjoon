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

const int MAX = 501;
int N,res[MAX],indegree[MAX],TIME[MAX];
vector<int> adj[MAX];

void solve(){
    cin >> N;
    queue<int> q;
    for(int i=0; i < N; i++){
        for(int j=0; ;j++){
            int a; cin >> a;
            if(a==-1) break;
            if(j==0) TIME[i] = a;
            else {
                a--;
                adj[a].push_back(i);
                indegree[i]++;
            }
        }
        if(indegree[i] == 0){ 
            q.push(i);
            res[i] = TIME[i];
        }
    }


    for(int i=0; i < N; i++){
        if(q.size() == 0){
            cout << -1; exit(0);
        }
        int curr = q.front();
        q.pop();

        for(auto next : adj[curr]){
            res[next] = max(res[next], res[curr]+ TIME[next]);
            indegree[next]--;
            if(indegree[next]==0) q.push(next);
        }
    }

    for(int i=0; i < N; i++){
        cout << res[i] << "\n";
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