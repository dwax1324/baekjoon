#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
// #define int int64_t
/*
    2021.01.30 Fri
    comment:   
    자료구조 트리
*/

const int MAX = 1e5+1;
int N,R,Q,size1[MAX],vi[MAX];
vector<int>adj[MAX];
vector<int>child[MAX];

int makeTree(int curr){
    vi[curr] = true;
    size1[curr] = 1;
    for(auto next : adj[curr]){
        if(!vi[next]){
            child[curr].push_back(next);
            size1[curr] += makeTree(next);
        }
    }
    return size1[curr];
}
int32_t main(){
    fastio;
    cin >> N>> R >> Q; R--;
    for(int i=0; i < N-1; i++){
        int u,v; cin>> u >> v; u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    makeTree(R);
    for(int i=0; i <Q ;i++){
        int q; cin >> q; q--;
        cout << size1[q] << endl;
    }

}