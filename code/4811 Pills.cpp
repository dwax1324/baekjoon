#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define int int64_t
void misc(int32_t &t);
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.12.29
    comment: 
    풀긴 풀었는데 
    검색해보니까 
    days는 필요없는 정보다..
    one,half 으로만 풀 수있다.


⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


int dp[61][31][31];
int n;

int go(int day, int one, int half){
    if(day == 2*n){
        if(!one && !half){
    // printf("day: %d, one: %d, half: %d\n",day,one,half);
            // cout << 1;
            return 1;
        }
        return 0;
    }
    int &ret= dp[day][one][half];
    if(ret!= -1) return ret;
    ret=0;
    if(half){
        ret = go(day+1,one,half-1);
    }
    ret += go(day+1,one-1,half+1);
    return ret;

}
void solve(){

    memset(dp,-1,sizeof(dp));
    while(1){
        cin >> n;
        if(!n) break;
        cout << go(0,n,0) << '\n';
    }
}


int32_t main() {
    int32_t T = 1;
    misc(T);
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        // cout << "Data Set "<< i << ":\n";
        // cout << "case #" << i << ": ";
        solve();
    }
}

void misc(int32_t &T){
    fastio;
 //   debug;  
}