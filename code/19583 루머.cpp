// date: Fri Mar 5 05:00:57 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n; cin >> n;
    vector<int>adj[200001];
    int vis[200001]={},deg[200001]={};
    memset(vis,-1,sizeof(vis));
    for(int i=0; i < n; i++){
        while(1){
            int a; cin >> a; if(!a)break;a--;
            adj[i].push_back(a);
            deg[a]++;
        }
    }
    int m; cin >> m;
    queue<int> q;
    for(int i=0; i < m; i++){
        int a; cin >> a; a--;
        vis[a]=0;
        q.push(a);
    }
    while(q.size()){
        int curr=  q.front(); q.pop();
        for(auto next: adj[curr]){
            deg[next]--;
            if(vis[next]==-1 && deg[next] <= (adj[next].size())/2){
                q.push(next);
                vis[next] = vis[curr]+1;
            }
        }
    }
    for(int i=0; i < n; i++) cout << vis[i] << ' ';

}
}