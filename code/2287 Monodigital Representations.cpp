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
    2021.01.22 Fri
    comment: 
    set을 이용한 dp
    이게 뭡니까??

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int k;
set<int> val[9];

void bruteForce(int limit){
    if(limit == 0) return;
    if(!val[limit].empty()) return;

    int kk =k;
    for(int i=1; i< limit; i++) kk = kk*10 + k;

    val[limit].insert(kk);
    val[limit].insert(-kk);

    for(int i=1; i< limit; i++){

        bruteForce(i);
        bruteForce(limit-i);
        for(auto A : val[i])
            for(auto B : val[limit-i]){

                if(i<= limit/2){
                    val[limit].insert(A+B);
                    val[limit].insert(A-B);
                    val[limit].insert(A*B);
                }
                if(B) val[limit].insert(A/B);

            }
    }

}

void solve(){
    int n,dest; 
    cin >> k >> n;
    val[0].insert(0);
    bruteForce(8);

    for(int i=0; i < n; i++){
        cin >> dest;
        int res =0;
        for(; res<= 8 && val[res].find(dest) == val[res].end(); res++);
        if(res == 9) cout << "NO\n";
        else cout << res << '\n';
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