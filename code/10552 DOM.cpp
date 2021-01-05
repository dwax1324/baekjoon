#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.01.05 Tue
    comment: 
    그래프

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


int to[100001],vi[100001];


int dfs(int cur){
    vi[cur] = true;
    int next = to[cur];
    if(next == -1) return 0;
    if(vi[next]) return -1;

    int ret = dfs(next);
    return ret == -1 ? -1 : ret +1;
}


void solve(){

    int n,m,p;
    cin >> n >> m>> p;
    p--;
    memset(to,-1,sizeof(to));
    for(int i=0; i < n; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        if(to[b] == -1) to[b] = a;
    }
    cout << dfs(p);
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