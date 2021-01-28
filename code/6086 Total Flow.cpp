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

    Network Flow
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX_V = 52;
const int INF = 1<<30;

// 정점 문자를 0~51 사이의 번호로 바꿔주는 간단한 함수

int CtoI(char c){
    if(c<= 'Z') return c - 'A';
    return c-'a'+26;
}


void solve(){
    int N;
    int c[MAX_V][MAX_V] = {0};
    int f[MAX_V][MAX_V] = {0};
    vector<int> adj[MAX_V];

    // 간선 정보 입력받기

    cin >> N;
    for(int i=0; i < N; i++){
        char u,v; int w; cin >> u >> v >> w;
        u = CtoI(u); v = CtoI(v);
        c[u][v] = c[v][u] += w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // tot: 
    int tot = 0, S = CtoI('A'), E = CtoI('Z');

    while(1){
        int prev[MAX_V];
        fill(prev, prev+MAX_V,-1);
        queue<int> Q;
        Q.push(S);

        while(Q.size() && prev[E] == -1){
            int curr =Q.front();
            Q.pop();
            for(auto next : adj[curr]){
                if(c[curr][next] - f[curr][next] > 0 && prev[next] == -1){
                    Q.push(next);
                    prev[next] = curr;
                    if(next == E) break;
                }
            }
        }
        if(prev[E] == -1) break;
        int flow = INF;
        for(int i=E; i != S; i= prev[i])
            flow  =min(flow, c[prev[i]][i]-f[prev[i]][i]);
        
        for(int i=E; i!=S;i=prev[i]){
            f[prev[i]][i] += flow;
            f[i][prev[i]] -= flow;
        }
        tot += flow;
    }
    cout << tot;
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