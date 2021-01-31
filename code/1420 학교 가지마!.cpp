#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
typedef pair<int,int> pi;
typedef tuple<int,int,int> tii;
// #define int int64_t
/*
    2021.01.28 Fri
    comment:   
    min-cut / max-flow therorem
*/

struct Edge{
    int to,c,f;
    Edge *r;
    Edge(): Edge(-1,0){}
    Edge(int to1,int c1): to(to1),c(c1),f(0),r(nullptr){}
    int spare(){
        return c-f;
    }
    void addFlow(int f1){
        f += f1;
        r->f -= f1;
    }
};

vector<Edge*> adj[20000];
void addEdge(int a, int b, int cap){
    Edge * ab = new Edge(b,cap), *ba = new Edge(a,0);
    ab->r = ba;
    ba->r = ab;

    adj[a].push_back(ab);
    adj[b].push_back(ba);

}


const int INF=1<<30;
int N,M,S,E;
char map_[100][100];
int32_t main(){
    scanf("%d %d\n",&N,&M);
    for(int i=0; i < N; i++){
        for(int j=0; j < M ;j++){
            map_[i][j] = getchar();
            if(map_[i][j] == 'K') S = 2*(i*M+j)+1;
            else if (map_[i][j] == 'H') E= 2*(i*M+j);
        }
        getchar();
    }
    for(int i=0; i < N; i++){
        for(int j=0; j < M; j++){
            if(map_[i][j] == '#') continue;
            if(map_[i][j] == 'H'){
                for(int d=0; d < 4; d++){
                    int ni = i +"2011"[d]-'1';
                    int nj = j +"1102"[d]-'1';
                    if(ni >=0 && nj >=0 && ni < N && nj < M && map_[ni][nj] == 'K'){
                        puts("-1"); return 0;
                    }
                }
            }

            int c1 = 2*(i*M+j), c2 = c1 +1;
            addEdge(c1,c2,1);

            for(int d=0; d <4 ;d++){
                int ni= i + "2011"[d]-'1';
                int nj= j + "1102"[d]-'1';
                if(ni <0 || nj <0 || ni >= N || nj >= M || map_[ni][nj] =='#') continue;
                int n1 = 2*(ni*M+nj), n2 = n1+1;
                addEdge(c2,n1,INF);
            }
        }
    }
    int result =0;

    while(1){
        int prev[20000];
        fill(prev,prev+20000, -1);
        Edge*path[20000] = {nullptr};
        queue<int> Q;
        Q.push(S);

        while(Q.size() && prev[E] == -1){
            int curr = Q.front(); Q.pop();
            for(auto *e : adj[curr]){
                int next = e->to;
                if(e->spare() && prev[next]==-1){
                    path[next] = e;
                    prev[next] = curr;
                    Q.push(next);
                }
            }
        }
        if(prev[E] == -1) break;

        int flow = 1<<30;
        for(int i=E; i!= S; i= prev[i])
            flow = min(flow,path[i]->spare());
        for(int i=E; i!= S; i= prev[i])
            path[i]->addFlow(flow);
            
        result += flow;
    }
    printf("%d\n",result);
}