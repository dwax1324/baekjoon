#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.28 Thu
    comment: 
    2-SAT

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX = 10001 *2;
int N,M,SN,sn[MAX],dfsn[MAX],finished[MAX],cnt=0;
vector<int> adj[MAX];
stack<int> stk;

int oppo (int a){ return a%2 ? a-1 : a+1 ; }

int DFS(int curr){
    stk.push(curr);
    int ret = dfsn[curr] = ++cnt;
    
    for(auto next : adj[curr]){
        if(!dfsn[next]) ret = min(ret,DFS(next));
        else if (!finished[next]) ret = min(ret,dfsn[next]);
    }

    if(ret == dfsn[curr]){
        while(1){
            int t = stk.top(); stk.pop();
            sn[t]= SN;
            finished[t] = true;
            if(t == curr) break;
        }
        SN++;
    }
    return ret;
}


void solve(){
    cin >> N>> M;
    for(int i=0; i < M;i++){
        int a,b; cin >> a >> b;
        a = a <0 ? (a+1)*-2 : a*2-1;
        b = b <0 ? (b+1)*-2 : b*2-1;
        adj[oppo(a)].push_back(b);
        adj[oppo(b)].push_back(a);
    }

    for(int i=0; i < N*2; i++){
        if(dfsn[i] == 0) DFS(i);
    }

    for(int i=0; i < N; i++){
        if(sn[i*2] == sn[i*2+1]) {
            cout << 0; exit(0);
        }
    }
    cout << 1;

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