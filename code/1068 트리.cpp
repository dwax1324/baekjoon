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
    
    자식 노드가 하나이면서 지워진 노드면 정답에 1을 추가한다


⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int n;
int dn;
vector<int> child[51];
int vi[51];
int ans=0;
void dfs(int cur){

    // cout << cur << " " <<  dn << '\n';
    if(cur== dn) {
        return;
    }
    if(child[cur].size() == 0){
        ans++;
        return;
    }else if(child[cur].size()== 1 && child[cur][0] == dn){
        ans++;
        return;
    }else{
        for(int i=0; i < child[cur].size(); i++){
            int next = child[cur][i];
            if(!vi[next]){
                dfs(next);
            }   
        }
    }

}

void solve(){

    cin >> n;
    int root;
    for(int i=0; i < n; i++) {
        int a; cin >> a;
        if(a==-1) root =i;
        else child[a].push_back(i);
    }
    cin >> dn;
    dfs(root);

    cout << ans;
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