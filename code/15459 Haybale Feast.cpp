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
#define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.23 Sat
    comment: 
    유니온파인드
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

#define MAX 100000
struct unionFind{
    int p[MAX];
    int find(int a){
        if(p[a] < 0 )return a;
        return p[a] = find(p[a]);
    }

    void union_(int a, int b){
        a = find(a);
        b = find(b);
        if(a== b ) return ;
        if(p[a] > p[b]) swap(a,b);
        p[a] += p[b];
        p[b]= a;
    }
    int size(int a) {return -p[find(a)];}
};


void solve(){
    int n,m;
    cin >> n>> m;
    pii p[MAX];
    unionFind UF;
    for(int i=0; i < n; i++){
        int F,S;
        cin >> F >>S ;
        UF.p[i] = -F;
        p[i] = {S,i};
    }

    sort(p,p+n);

    bool vi[MAX] = {false,};

    for(int i=0; i < n; i++){
        int j= p[i].o2;
        vi[j] = true;
        if(j >0 && vi[j-1]) UF.union_(j,j-1);
        if(j < n-1 && vi[j+1]) UF.union_(j,j+1);
        if(UF.size(j) >= m){
            cout << p[i].o1;
            break;
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