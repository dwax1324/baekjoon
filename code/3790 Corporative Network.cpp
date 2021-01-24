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
    2021.01.23 Sun
    comment: 
    유니온파인드
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int p[20001], length[20001];

struct unionFind{
    
    pii findLength(int a){
        if(p[a] <0 ) return {a,0};
        pii temp = findLength(p[a]);
        p[a] = temp.o1;
        length[a] += temp.o2;
        return {p[a],length[a]};
    }

    void union_(int a, int b){
        int aCenter = findLength(a).o1;
        int bCenter = findLength(b).o1;

        if(aCenter != bCenter){
            length[aCenter] = (int)(abs(a-b)) % 1000;
            p[aCenter] = b;
        }
    }
};



void solve(){
    int T; cin >> T;
    unionFind uf;
    while(T--){

        int n; cin >> n;
        memset(p,-1,sizeof(p));
        memset(length,0,sizeof(length));
        while(1){
            char a; cin >> a;
            if(a == 'O') break;
            else if(a == 'E'){
                int b; cin >> b;
                cout << uf.findLength(b-1).o2 << '\n';
            }else{
                int c,d; cin >> c >> d;
                uf.union_(c-1,d-1);
            }

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