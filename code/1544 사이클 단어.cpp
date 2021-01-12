#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.08 Fri
    comment: 
    구현, 완탐, 덱을이용해풀었다.

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

void solve(){

    int n;
    cin >> n;
    set<string>ans;
    int arr[26];
    vector<string> v;
    for(int i=0; i < n; i++){     
        string s; cin >> s;   
        if(!v.size()) {
            v.push_back(s);
            continue;
        }
        
        deque<char> dq;
        for(int j=0; j < s.size(); j++){
            dq.push_back(s[j]);
        }

        bool isSame= false;
        for(int z=0; z < v.size(); z++){
            if(dq.size() == v[z].size()){
                for(int j=0; j < s.size(); j++){
                    bool isAllSame=  true;
                    for(int kk =0; kk < s.size(); kk++){
                        if(dq[kk] != v[z][kk]) isAllSame=false;
                    }
                    if(isAllSame) {
                        isSame=true;
                        break;
                    }
                    char temp = dq[0];
                    dq.pop_front();
                    dq.push_back(temp);
                }
            }
        }
        if(!isSame) v.push_back(s);

    }
    cout << v.size();


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