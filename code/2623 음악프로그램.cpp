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

int N,M, indegree[1001];
vector<int> adj[1001];
void solve(){
    cin >> N>> M;
    for(int i=0 ; i< M; i++){
        int K, prev , curr; 
        cin >> K;
        if(K==0) continue;
        cin >> prev; prev--;
        for(int i=1; i < K; i++){
            cin >> curr; curr--;
            indegree[curr]++;
            adj[prev].push_back(curr);
            prev = curr;
        }
    }

    int res[1001];
    queue<int> Q;
    // 위상정렬 시작: 큐에 indegree가 0인 정점을 다 넣음

    for(int i=0; i < N; i++)
        if(indegree[i] == 0 ) Q.push(i);

    for(int i=0; i < N; i++){
        if(Q.size() == 0){
            cout << 0;
            exit(0);
        }

        int curr = Q.front();
        Q.pop();
        res[i] = curr+1;
        // 인접한 정점을 순회하면서 indegree1씩 감소. 0이 되면 큐에 넣음
        for(auto next : adj[curr]){
            indegree[next]--;
            if(indegree[next] == 0) Q.push(next);
        }
    }
    for(int i=0; i < N; i++)
        cout << res[i] << '\n';

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