#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.12 Tue
    comment: 
    지울때는 포인터하나 새로 만들어서 지워야한다


⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

void solve(){
    int T; cin >> T; while(T--){
        string s;
        cin >> s;
        list<char> ans;
        auto iter = ans.begin();
        for(int i=0; i < s.size(); i++){
            if(s[i] == '<'){
                if(iter == ans.begin()) continue;
                iter--;
            }
            else if(s[i] == '>'){
                if(iter == ans.end()) continue;
                iter++;
            }else if(s[i] == '-'){
                if(iter == ans.begin()) continue;
                auto temp = iter;
                temp--;
                ans.erase(temp);
            }else{
                ans.insert(iter,s[i]);
            }
        }
        for(auto x : ans) cout << x;
        cout << '\n';
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