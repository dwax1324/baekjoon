#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.15 Fri
    comment: 
    유니온파인드
    small 이기 때문에 구현가능
    배열을 칸으로 생각하다 구현하다 막힘
    배열을 벽으로 생각하면 쉽게 구현 가능함


⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int arr[101];
void solve(){

    int n,m;
    cin >> n >> m;
    for(int i=0; i < m; i++){
        int a,b;
        cin >> a >> b;
        for(int j=a; j<b; j++){
            arr[j] = 1;
        }
    }
    int ans=0;

    for(int i=1; i<= n; i++){
        if(arr[i] == 0) ans++;
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