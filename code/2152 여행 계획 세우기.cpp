#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef tuple<int,int> tii;
typedef tuple<int,int,int> tiii;
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.27 Wed
    comment: 
    
    SCC + 위상정렬
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX = 100001;
int N,M,start,target;
int dfsn[MAX],finished[MAX],sn[MAX],SN=0,cnt=0;
vector<int> adj[MAX];
stack<int> stk;

int tarzan(int curr){
    stk.push(curr);
    int ret = dfsn[curr] = ++cnt;
    for(auto next : adj[curr]){
        if(dfsn[next] == 0) ret = min(ret, tarzan(next));
        else if(finished[next] == 0) ret= min(ret,dfsn[next]);
    }

    if(ret == dfsn[curr]){
        while(1){
            int t= stk.top(); stk.pop();
            sn[t] = SN;
            finished[t] = true;
            if(curr==t) break;
        }
        SN++;
    }
    return ret;
}


vector<int> sAdj[MAX];
int sStart,sTarget;
int sMax[MAX],sCities[MAX],sOutdegree[MAX];
bool sVi[MAX];

void sccInfo(){
    for(int i=0; i < N; i++){
        int si = sn[i];
        sCities[si] += 1;
        if(i == target) sTarget = si;
        if(i == start) sStart = si;

        for(int j : adj[i]){
            int sj = sn[j];
            if(si == sj) continue;
            sAdj[si].push_back(sj);
            sOutdegree[sj]++;
        }
    }
}

void topoSort(){
    queue<int> q;
    for(int i=0; i < SN; i++){
        sMax[i] = sCities[i];
        if(i == sStart) sVi[i] = true;
        if(sOutdegree[i] == 0) q.push(i);
    }

    while(q.size()){
        int curr= q.front(); q.pop();
        for(auto next: sAdj[curr]){
            if(sVi[curr]){
                sMax[next] = max(sMax[next],sMax[curr]+sCities[next]);
                sVi[next] =true;
            }
            sOutdegree[next]--;
            if(sOutdegree[next] == 0) q.push(next);
        }
    }


}


void solve(){
    cin >> N >> M >> start>> target; start--;target--;
    for(int i=0; i < M ;i++){
        int u,v; cin >> u >> v; u--;v--;
        adj[u].push_back(v);
    }
    for(int i=0; i < N; i++){
        if(dfsn[i] == 0) tarzan(i);
    }
    
    sccInfo();
    topoSort();

    sVi[sTarget] ? cout << sMax[sTarget] : cout << 0;

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