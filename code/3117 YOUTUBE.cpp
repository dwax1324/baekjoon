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
    2021.01.23 Sun
    comment: 
    스파스테이블

    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


int N,K,M,s[100001],arr[100001][31];

void solve(){
    cin >>K >> N >> M;
    M--;
    for(int i=0; i < K; i++){
        cin >> s[i];
        s[i]--;
    }

    memset(arr,-1,sizeof(-1));
    for(int i=0; i < N; i++){
        cin >> arr[i][0];
        arr[i][0]--;
    }

    for(int j=1; j< 31 ;j++)
        for(int i=0; i < N; i++)
            arr[i][j] = arr[arr[i][j-1]][j-1];
    
    for(int i=0; i < K; i++){
        int u= s[i], w = M;
        for(int j= 31-1; j >= 0; j--){
            if(w >= (1<<j)){
                w-= 1<<j;
                u = arr[u][j];
            }
        }
        cout << u+1 << '\n';
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