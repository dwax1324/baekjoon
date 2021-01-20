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
    2021.01.20 Wed
    comment: 
    각 자리수마다 9*자리수만큼의 숫자가 있다.

    다른풀이: 1의 자리수는 모두가 가지고있다.
    10의 자리수는 10~n까지의 수가 가지고있다.
    100의 자리수는 100~n까지의 수가 가지고있다.
    ...

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


int getLen(int a){
    int ret =0;
    while(a){
        a/=10;
        ret+=1;
    }
    return ret;
}



void solve(){
    int a;
    cin >> a;
    int length = getLen(a);

    int ans=0;

    int temp=1;
    for(int i=1; i< length; i++){
        ans += i*9*temp;
        // cout << ans << '\n';
        temp *= 10;
    }
    int remain= a-temp;
    remain +=1;
    // cout << length << " " << remain << '\n';
    ans += remain*length;
    // cout << (length == 1 ? ans+1 : ans);
    cout << ans;
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