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
#define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.27 Wed
    comment: 
    scc + topological sorting
    뒤지게 어렵넹..
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX= 500001;
int N,M,start,K,cnt=0,SN=0;
int sn[MAX],rest[MAX],atm[MAX],dfsn[MAX],finished[MAX];
vector<int> adj[MAX];
int sStart,sAtm[MAX],sOutdegree[MAX],sRest[MAX];
vector<int> sAdj[MAX];
// sStart : 시작점을 포함하는 SCC번호
// sAtm : 이 SCC의 현금 액수 총합
// sOutdegree : 이 SCC의 outdegree
// sRest : 이 SCC가 레스토랑을 포함하는지
// sAdj : 이 SCC와 인접한 SCC들을 담고 있는 리스트ㄴ
stack<int> stk;

int tarzan(int curr){

    stk.push(curr);
    int ret = dfsn[curr] = ++cnt;
    for(auto next : adj[curr]){
        if(dfsn[next] ==0) ret =min(ret,tarzan(next));
        else if(finished[next] == 0) ret= min(ret,dfsn[next]);
    }

    if(ret == dfsn[curr]){

        while(1){
            int t = stk.top(); stk.pop();
            sn[t] = SN;
            finished[t] = true;
            if(t == curr) break;
        }
        SN++;
    }
    return ret;
}

int sMax[MAX]; // 각 SCC의 결과값
bool sCal[MAX]; // 시작점에서 이 SCC로 도달할 수 있는가?
void topoSort(){
    // SCC 단위로 위상정렬 준비
    queue<int> Q;
    for(int i=0; i < SN; i++){
        sMax[i] = sAtm[i];// 결과값 초기화: 자신의 액수만큼은 채길 수 있음.
        if(i == sStart) sCal[i] = true;
        if(sOutdegree[i] == 0) Q.push(i); // outdegree가 0인 SCC를 큐에 넣음
    }

    // 위상정렬 시작

    while(Q.size()){
        int curr= Q.front(); Q.pop();
        for(auto next : sAdj[curr]){
            if(sCal[curr]){ // 시작점에서 이 SCC에 도달 가능해야만 next의 정보 갱신
                sMax[next] = max(sMax[next], sMax[curr] + sAtm[next]);
                sCal[next] = true;
            }
            sOutdegree[next]--;
            if(sOutdegree[next]==0) Q.push(next);
        }
    }

}

void sccInfo(){
    for(int i=0; i < N; i++){
        int si = sn[i];
        sAtm[si] += atm[i];
        if(rest[i]) sRest[si] = true;
        if(i== start) sStart = si;

        // sAdj를 채움
        for(int j : adj[i]){
            int sj = sn[j];
            if(si == sj) continue;
            // i,j 가 서로 다른 SCC에 포함될때만 간선 생성
            sAdj[si].push_back(sj);
            sOutdegree[sj]++;
        }
    }
}


void solve(){
    cin >> N>> M;
    for(int i=0; i < M; i++){
        int u,v; cin >> u >> v; u--;v--;
        adj[u].push_back(v);
    }
    for(int i=0; i < N; i++){
        cin >> atm[i];
    }
    cin >> start >> K; start--;
    for(int i=0; i < K; i++){
        int a; cin >> a; a--;
        rest[a] = true;
    }

    for(int i=0; i < N; i++){
        if(dfsn[i] == 0) tarzan(i);
    }
    // scc에 정보를 넘긴다.
    sccInfo();
    // 위상정렬을 한다.
    topoSort();

    int res =0;
    // scc중에서 가장 비용이 높은걸 택한다.
    for(int i=0; i < SN; i++)
        if(sRest[i] && sCal[i]) res = max(res,sMax[i]);
    
    cout << res;



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