#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
void misc(int32_t &t);
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.12.30
    comment: 

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


struct info{
    int table,time;
};

void solve(){
    int n,m;
    cin >> n >> m;
    vector<info>v;
    for(int i=0; i < n; i++){
        string s;
        cin >>s;
        if(s== "order"){
            info Info;
            cin >> Info.table >> Info.time;
            v.push_back(Info);
            for(auto x : v) cout << x.table << " ";
            cout << '\n';
        }else if(s== "sort"){
            sort(all(v),[](info a, info b){
                if(a.time == b.time) return a.table < b.table;
                return a.time < b.time;
            });
            if(v.size()){
                for(auto x : v) cout << x.table << " ";
                cout << '\n';
            }else{
                cout << "sleep\n";
            }
        }else{
            int a; cin >> a;
            for(int i=0; i < v.size(); i++){
                if(v[i].table == a){
                    v.erase(v.begin()+i);
                    break;
                }
            }
            if(v.size()){
                for(auto x : v)cout << x.table << " ";
                cout << '\n';
            }else{
                cout << "sleep\n";
            }

        }
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