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
    첫 사이클 디텍션 문제

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
int n, arr[100001],cntCycle;
bool visited[100001],finished[100001];

void dfs(int cur){

    visited[cur] = true;
    int next = arr[cur];
    if(visited[next]){
        if(!finished[next]){
            for(int i=next ; i!= cur ; i= arr[i]) cntCycle++;
            cntCycle++;
        }
    }else{
        dfs(next);
    }
    finished[cur] = true;
}



void solve(){

    int t; cin>> t; while(t--){
        cin >> n;
        for(int i=0; i < n; i++){
            cin >> arr[i];
            arr[i]--;
        }

        memset(visited,0,sizeof(visited));
        memset(finished,0,sizeof(finished));

        cntCycle = 0;
        for(int i=0; i < n; i++)
            if(!visited[i]) dfs(i);
        
        cout << n - cntCycle << '\n';

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