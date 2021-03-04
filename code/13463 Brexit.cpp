// date: Fri Mar 5 05:19:57 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int c,p,x,l;
    cin >> c >> p >> x >> l;x--;l--;
    vector<int> adj[200001];
    int deg[200001]={};
    bool vis[200001]={};
    for(int i=0; i < p; i++){
        int a,b; cin >> a >> b; a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;deg[b]++;
    }
    queue<int> q;
    q.push(l);
    vis[l]=1;
    while(q.size()){
        int curr = q.front(); q.pop();
        for(auto next: adj[curr]){
            deg[next]--;
            if(!vis[next] && deg[next] <= adj[next].size()/2){
                vis[next]=true;
                q.push(next);
            }
        }
    }
    if(vis[x]) cout << "leave";
    else cout << "stay";

}
}