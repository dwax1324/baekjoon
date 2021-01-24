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
    2021.01.23 Sat
    comment: 
    유니온파인드
    루트를 기준으로 최소비용을 저장하는 배열을 만든다.  
    각 컴포넌트마다 최소의 값을 더해주면된다.

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
int cost[10001];
int mincost[10001];
int p[10001];

int find(int a){
    if(p[a] == -1) return a;
    p[a] = find(p[a]);
    return p[a];
}

void union_(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b ) return;
    p[b] = a;
}


void solve(){
    int n,m,k;
    cin >> n>> m >> k;
    memset(p,-1,sizeof(p));
    for(int i=0; i < n; i++){
        cin >> cost[i];
    }

    for(int i=0; i < m; i++){
        int a,b; cin >> a >> b; a--;b--;
        union_(a,b);
    }
    fill(mincost,mincost+10000,1<<30);
    for(int i=0; i < n; i++){
        int temp = find(i);
        mincost[temp] = min({mincost[temp], cost[temp] , cost[i]});
    }

    int ans= 0;

    for(int i=0; i < n; i++){
        if(mincost[i] != 1<<30) ans += mincost[i];
    }

    ( ans > k ? cout << "Oh no" : cout << ans);


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