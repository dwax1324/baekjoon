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
    2021.01.23 Sun
    comment: 
    유니온파인드 자료구조는 유니온과 파인드연산만을 지원한다.
    이 문제의 경우 집합을 분리하려하는데 어떻게 할까?

    역발상이 필요하다.

    이미 잘려잔 최종상태를 초기상태로 하고
    잘랐던 역순서대로 다시 붙여나가면서 그 비용을 구한다.
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


int p[100001];

struct unionFind{

    int find(int a){
        if(p[a] < 0) return a;
        return p[a] = find(p[a]);
    }

    void union_(int a, int b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        if(p[a] > p[b]) swap(a,b);
        p[a] += p[b];
        p[b] = a;
    }

    int size(int a){ return -p[find(a)]; }

};





void solve(){
    int N,M,Q;
    cin >> N>> M>> Q;
    memset(p,-1,sizeof(p));

    unionFind UF;
    vector<tuple<int,int,int>> v(M);
    for(int i=0; i < M; i++){
        int a,b; cin >> a >> b;
        v[i] = {1,a,b};
    }

    stack<int> stk;
    for(int i=0; i < Q; i++){
        int a; cin >> a;
        get<0>(v[a-1]) = 0;
        stk.push(a);
    }

    for(int i=0 ; i < M; i++){
        int first = get<0>(v[i]);

        if(first == 1){
            UF.union_(get<1>(v[i]), get<2>(v[i]));
        }
    }
    int ans=0;
    while(stk.size()){
        int cur = stk.top();
        int a,b,c;
        tie(a,b,c) = v[cur-1];
        if(UF.find(b) != UF.find(c)){
            ans += UF.size(b) * UF.size(c);
        }
        UF.union_(b,c);

        
        stk.pop();

    }

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