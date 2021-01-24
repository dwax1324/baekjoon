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
    2021.01.23 Sat
    comment: 

    유니온파인드 / 크루스칼
    
    간선을 크기순으로 정렬, 차례대로 유니온파인드 진행

    4 5 50  4,5
    5 6 42  4,5,6
    1 3 27  4,5,6/ 1,3
    0 2 23  4,5,6/ 1,3 / 0,2
    2 6 21  4,5,6,2,0/ 1,3
    1 2 16  4,5,6,2,0,1,3  -> 시작점(3) 과 끝점(5)가 같은 집합에 속하므로 종료
    0 1 15
    3 4 14
    3 5 10
    4 6 9
    2 4 3

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

struct edges{
    int u,v,cost;
};

struct unionFind{
    int p[1001];
    unionFind(){ 
        for(int i=0; i < 1001; i++)
            p[i] = i;
    }

    int find(int a){
        if(p[a] == a) return a;
        return p[a] = find(p[a]);
    }

    void union_(int a, int b){
        a = find(a);
        b = find(b);

        if(a==b) return;
        
        p[b] = a;
    }
};

bool cmp(edges a, edges b){
    return a.cost > b.cost;
}


void solve(){
    int p,w,c,v;
    cin >> p >> w >> c >> v;

    vector<edges> vec;
    for(int i=0; i< w; i++){
        edges E;
        cin >> E.u >> E.v >> E.cost;
        vec.push_back(E);
    }

    unionFind uf;

    sort(all(vec),cmp);

    for(auto edge : vec){
        uf.union_(edge.u,edge.v);
        // cout << uf.find(c) << " " << uf.find(v) << '\n';
        if(uf.find(c) == uf.find(v)){
            cout << edge.cost;
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