#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.13 Wed
    comment: 
    매번 쿼리할때마다 세어주면 시간초과
    양옆에 1이 있으면 +,- 해주는 식으로 구현함

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
vector<int> v;
int n,m;
bool vi[1000001];

void dfs(int a){
    for(;;){
        if(!vi[a] && v[a] ==1 && a< n){
            vi[a]=true;
        }else{
            break;
        }
        a++;
    }
}
void solve(){

    cin >> n >> m;
    for(int i=0;i <n ;i++){
        int a; cin >> a; v.push_back(a);
    }
    int cur =0;

    for(int i=0; i< n; i++){
        if(!vi[i] && v[i] == 1){
            dfs(i);
            cur++;
        }
    }

    for(int i=0; i< m; i++){
        int o,a; cin >> o;
        if(o ==1) {
            cin >> a;
            a--;
            if(v[a]) continue;
            v[a] = 1;
            if(a == 0){
                if(v[a+1] == 0) cur++;
            }else if(a== n-1){
                if(v[a-1] == 0) cur++;
            }else{
                if(v[a-1] == 1 && v[a+1] == 1) cur--;
                else if(v[a-1] ==0 && v[a+1] ==0 ) cur++;
            }
        }else{
            cout << cur << '\n';    
        }
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