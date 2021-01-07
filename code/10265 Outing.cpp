#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.01.06 Wed
    comment: 
    dp+ 사이클,컴포넌트
    kks227 풀이참조


⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int N,cnt,adj[1001],dfsn[1001];
bool finished[1001];
int SN, scc[1001], sSize[1001], sAdj[1001];
stack<int> S;
int K, DN, minW[1001], maxW[1001], dp[1001][1001];

int maxPassenger(int pos, int remain){
    if(pos == DN) return 0;
    int &ret = dp[pos][remain];
    if(ret!=-1) return ret;

    ret = maxPassenger(pos+1, remain);

    if(remain >= minW[pos]){
        for(int i=minW[pos]; i<= maxW[pos] && i<= remain; i++)
            ret =max(ret, maxPassenger(pos+1,remain-i)+i);
    }
    return ret;
}


int DFS(int cur){

    dfsn[cur] = ++cnt;
    S.push(cur);
    int ret = dfsn[cur], next =adj[cur];
    if(dfsn[next] ==0 ) ret = min(ret,DFS(next));
    else if(!finished[next]) ret = min(ret,dfsn[next]);

    if(ret >= dfsn[cur]){
        int cnt=0;
        while(1){
            int n= S.top();
            S.pop();
            cnt++;
            scc[n] = SN;
            finished[n] = true;
            if(n== cur) break;
        }
        sSize[SN++] = cnt;
    }
    return ret;

}

void pushW (int cur){

    int next = sAdj[cur];
    if(next == cur || maxW[cur] == 0) return;
    maxW[next] += maxW[cur];
    minW[cur]= maxW[cur]=0;
    pushW(next);
}

bool is0(int n) {return !n;}

void solve(){
    cin >> N >> K;
    for(int i=0; i < N; i++){
        cin >> adj[i];
        adj[i]--;
    }

    for(int i=0; i < N; i++)
        if(dfsn[i] ==0) DFS(i);
    
    for(int i=0; i< N; i++)
        sAdj[scc[i]] = scc[adj[i]];
    
    for(int i=0; i< SN; i++)
        minW[i] = maxW[i] = sSize[i];
    
    for(int i=0; i< SN; i++)
        pushW(i);
    
    DN= remove_if(minW, minW+SN, is0) - minW;
    remove_if(maxW, maxW+SN, is0);

    memset(dp,-1,sizeof(dp));
    cout << maxPassenger(0,K);
    

    

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