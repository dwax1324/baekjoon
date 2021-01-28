#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.28 Thu
    comment: 
    처음 생각난건 세그트리였고
    prefix sum을 이용하려다가
    그냥 합계tot만 조작하면 된다는 사실을 알았다.

    지금 생각해보니 prefix에 변화가있는데
    prefix를 쓰려했네 ㅋㅋ
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


void solve(){
    int n,q; cin >> n >> q;
    int sum[200001]={0};
    vector<int> v(n);
    for(int i=0; i < n; i++){
        cin >> v[i];
    }

    int tot=0;
    for(int i=0; i < n; i++){
        int k =1;
        for(int j=i; j < i+4; j++){
            int t= j;
            if(t >= n) t%=n;
            k *= v[t];
        }
        tot+=k;
        sum[i+1] = k;
    }

    for(int Q=0; Q<q; Q++){
        int a; cin >> a;
        int cnt=0;
        while(1){
            if(cnt == 4) break;
            sum[a] = -sum[a];
            tot += sum[a]*2;
            a--;
            if(a<1) a=n;
            cnt++;
        }
        cout << tot << '\n';
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