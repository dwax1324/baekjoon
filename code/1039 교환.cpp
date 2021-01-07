#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.01.07 Thu
    comment: 
    bfs -> 완탐

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

void solve(){

    string n;
    int k;
    map<string,int> vi;
    cin >> n >> k;

    queue<string> q,tq;
    q.push(n);
    int ans=-1;
    for(;q.size();k--){
        int qSize = q.size();
        vi ={};
        tq=q;
        // cout << qSize << '\n';
        for(int i=0; i < qSize; i++){
            string cur = q.front(); q.pop();
            if(k==0){
                ans= max(ans,stoi(cur));
            }
            for(int j=cur.size()-1; j >=0; j--){
                for(int j2=j; j2>= 0; j2--){
                    if(j== j2) continue;
                    swap(cur[j],cur[j2]);
                    if(cur[0] == '0'){
                        swap(cur[j],cur[j2]);
                        continue;
                    }
                    // cout << cur << '\n';
                    if(vi[cur] != 1){
                        q.push(cur);
                        vi[cur] =1;
                    }
                    swap(cur[j],cur[j2]);
                }
            }

        }
        // cout << q.size() << '\n';
        if(k==0) break;
    }
    if(k>0) cout << -1;
    else cout << ans;
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