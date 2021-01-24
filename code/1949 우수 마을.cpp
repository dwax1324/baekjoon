#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define _1 first
#define _2 second
#define pii pair<int,int>
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.22 Fri
    comment: 
    트리위의 dp
    이전 노드에 따라 현재노드를 선택 or 선택하지않는다.

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int n;
int val[10001];
int vi[10001];
int dp[10001][2];
vector<int> edges[10001];

int go(int cur , int prev){
    
    int&ret = dp[cur][prev];
    if(ret!= -1) return ret;

    ret=0;
    vi[cur]=true;

    for(int i=0; i < edges[cur].size();i++){
        int next= edges[cur][i];
        if(!vi[next]){

                int temp = go(next,0);
                if(prev == 0) temp = max(temp,go(next,1));
                ret += temp;

        }
    }
    vi[cur]=false;
    
    return ret += (prev == 1 ? val[cur] : 0);
}

void solve(){
    cin >> n;
    for(int i=0; i < n; i++){
        cin >> val[i];
    }

    for(int i=0; i < n-1; i++){
        int a,b; cin >> a >> b; a--;b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    memset(dp,-1,sizeof(dp));
    vi[0] = true;
    cout <<  max(go(0,0),go(0,1));


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