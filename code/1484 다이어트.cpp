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

    투포인터
    종료조건: 끝점과 시작점이 1차이가 나면서 무게 >G 이면 종료.
    이 때부터는 인접한 수들마저 항상 제곱수의 차가 G보다 커서 절대 더이상 답이 안나옴.
    


⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


void solve(){
    int G;
    cin >> G;


    int s=1,e=1,weight=0;
    vector<int> ans;

    while(1){
        weight = e*e -s*s;
        if(weight >= G){
            if(e-s == 1 && weight > G) break;
            s++;
        }else{
            e++;
        }
        // printf("%"
        if(weight == G) ans.push_back(e); 
    }

    if(ans.size() == 0) cout << -1;
    else for(auto x : ans) cout << x << '\n';

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