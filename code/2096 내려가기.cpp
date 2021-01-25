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
    2021.01.25 Mon
    comment: 
    슬라이딩 윈도우 + dp
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


void solve(){
    int colMax[3] = {0}, colMin[3] ={0}, tempMax[3] ={0}, tempMin[3] ={0},N;
    cin >> N;
    for(int i=0; i < N; i++){
        for(int j=0; j < 3; j++){
            cin >> tempMax[j];
            tempMin[j] = tempMax[j];
            tempMax[j] += max( colMax[1], (j==1) ? max(colMax[0], colMax[2]) : colMax[j]);
            tempMin[j] += min( colMin[1], (j==1) ? min(colMin[0], colMin[2]) : colMin[j]);
        }
        memcpy(colMax, tempMax, sizeof(int)*3);
        memcpy(colMin, tempMin, sizeof(int)*3);
    }
    sort(colMax, colMax+3);
    sort(colMin, colMin+3);
    cout << colMax[2] << " " << colMin[0];

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