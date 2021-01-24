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
    g,g-1,g-2... 1,0까지 유니온시켜준다.
    새로들어온 노드의 루트가 0이면 더이상 자리가 없다.
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int p[100001];

struct unionFind{
    int find(int a){
        if(p[a] < 0 ) return a;
        return p[a] = find(p[a]);
    }

    void union_(int a,int b){
        a = find(a);
        b = find(b);
        if(a == b) return;
        p[b] = a;
    }
};



void solve(){
    int G,P;
    cin >> G >> P;
    unionFind UF;
    memset(p,-1,sizeof(p));
    vector<int> v(P);
    int ans=0;
    for (int i=0; i < P ;i++){
        cin >> v[i];
    }

    for(int i=0; i < P; i++){
        int root = UF.find(v[i]);
        // 새로운 노드의 루트가 0이라면 자리가 꽉찼다.
        if(root == 0 ) break;
        // 아니라면 그 루트와 루트-1와 유니온해준다.
        ans++;
        UF.union_(root-1, root);
    }
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