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
    *중위순회 -> 너비구하기가능
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

pii child[10001];
int parent[10001];
pii diameter[10001];

int cnt=1;
int maxLevel =0;
void inorder(int cur, int level){

    if(child[cur].o1 != -1)
    inorder(child[cur].o1,level+1);

    // cout << cur << " " << level << '\n';
    diameter[level].o1 = min(diameter[level].o1 , cnt);
    diameter[level].o2 = max(diameter[level].o2 , cnt);
    maxLevel = max(level,maxLevel);
    cnt++;
    if(child[cur].o2 != -1)
    inorder(child[cur].o2,level+1);
}

void solve(){
    int n;
    cin >> n;
    for(int i=1; i<= n; i++){
        diameter[i].o1 = 1<<30;
        diameter[i].o2 = -1;
    }

    for(int i=0; i < n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        child[a].o1 = b;
        child[a].o2 = c;
        if(b != -1) parent[b] = a;
        if(c != -1) parent[c] = a;
    }
    int root;
    for(int i=1; i <= n; i++){
        if(parent[i] == 0) root= i;
    }
    
    inorder(root,1);

    int ans=0;
    for(int i=1; i<= maxLevel; i++){
        ans = max(diameter[i].o2 -diameter[i].o1,ans);
    }

    for(int i=1; i<= maxLevel ; i++){
        if(diameter[i].o2 - diameter[i].o1 == ans){
            cout << i  << " " << ans+1;
            break;
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