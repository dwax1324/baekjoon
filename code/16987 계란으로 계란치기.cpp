#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.20 Wed
    comment: 
    문제를 그대로 읽고 백트래킹 구현
    배열을 빼주고 다시 원상복구 안해줘서 오류

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

typedef pair<int,int> pii;
int n;
vector<pii> v;

int ans=-1;
void go(int cur){
    if(cur == n){
        int ret= 0;
        for(int i=0; i< n; i++){
            if(v[i].o1 <=0) ret++;
        }
        ans = max(ret,ans);
        return;
    }

    if(v[cur].o1 <=0) return go(cur+1);
    bool isThereEggs = false;
    for(int i=0; i< n; i++){
        if(i!= cur && v[i].o1 > 0){
            v[cur].o1 -= v[i].o2;
            v[i].o1 -= v[cur].o2;
            isThereEggs = true;
            go(cur+1);
            v[cur].o1 += v[i].o2;
            v[i].o1 += v[cur].o2;

        }
    }
    if(isThereEggs == false){
        return go(cur+1);
    }
}


void solve(){
    cin >> n;
    for(int i=0; i< n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }

    go(0);
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