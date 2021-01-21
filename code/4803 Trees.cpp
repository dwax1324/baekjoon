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
    2021.01.21 Thu
    comment: 

    한 그래프 안의 컴포넌트들 속에서
    트리를 찾아내는 문제

    트리는 정점이 n개고 간선이 n-1개면 된다.
    정점이 n개고 간선이 n-1개면 사이클이 발생할 수도 없다.

    결국은 각 컴포넌트의 정점과 간선의 갯수를 세는 문제다.

    하나의 함수 안에서 정점과 간선의 갯수를 같이 세보려했는데 잘 안됐다.
    간선을 세는 방법이 아직 정확히 이해가 안된다.

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int vi[501];
int viEdges[501];
vector<int> edges[501];

int dfs(int cur){
    int cntNodes=1;
    vi[cur] = true;
    for(int i=0; i < edges[cur].size(); i++){
        int next = edges[cur][i];
        if(!vi[next]){
            cntNodes += dfs(next);
        }
    }
    return cntNodes;
}

int dfsEdges(int cur){

    viEdges[cur] = true;
    int ret= edges[cur].size();
    for(int i=0; i < edges[cur].size();i++){
        int next = edges[cur][i];
        if(!viEdges[next]) ret+= dfsEdges(next);
    }

    return ret;
}


void solve(){


    int n,m,T=1;
    while(1){
    
    memset(vi,0,sizeof(vi));
    memset(viEdges,0,sizeof(viEdges));

    memset(edges,0,sizeof(edges));
    cin >> n >> m;
    if(!n && !m) break;

    for(int i=0; i< m; i++){
        int a,b; cin >> a>> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int trees= 0;
    for(int i=1; i <= n; i++){
        if(!vi[i]){
            int Nodes = dfs(i);
            int Edges = dfsEdges(i)/2;
            if( Nodes -  Edges == 1)  trees++;
            // printf("Nodes: %d , Edges : %d\n" ,Nodes,Edges);
        }
    }
    cout << "Case " << T++ << ": "; 
    if(trees == 0){
        cout << "No trees.\n";
    }else if (trees ==1){
        cout << "There is one tree.\n";
    }else{
        cout << "A forest of " << trees << " trees.\n";
    }

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