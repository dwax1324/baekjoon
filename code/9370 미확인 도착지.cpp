// date: Tue Mar 2 14:47:46 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;



const int INF = 1e9;
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int tt; cin >> tt ; while(tt--){
    bool targets[2001]={};
    vector<pii> adj[2001];
    int n,m,t; cin >> n >> m >> t;
    int s,g,h; cin >> s >> g >> h; s--;g--;h--;
    for(int i=0; i < m; i++){
        int u,v,w; cin >> u >> v >> w; u--;v--;
        adj[u].push_back({w,v});
        adj[v].push_back({w,u});
    }
    for(int i=0; i < t; i++) {
        int a; cin >> a; a--; targets[a]=1;
    }

    // @ F dijkstra
    auto dijkstra =[&](int s, int e){
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        int dist[2001]={};
        bool vis[2001] ={};
        fill(dist,dist+2001,INF);
        pq.push({0,s});
        dist[s] = 0;
        while(pq.size()){
            int curr = pq.top().second; pq.pop();
            if(vis[curr]) continue;
            vis[curr] = true;
            for(auto i : adj[curr]){
                int next = i.second, d = i.first;
                if(dist[next] > dist[curr] + d){
                    dist[next] = dist[curr] + d;
                    if(!vis[next]){
                        pq.push({dist[next],next});
                    }
                }
            }
        }
        return dist[e];

    };


    int sg = dijkstra(s,g), gh = dijkstra(g,h);
    int sh = dijkstra(s,h), hg = dijkstra(h,g);

    for(int i=0; i < n; i++){
        if(targets[i]){
            // cout << sg << ' ' << gh << ' ' << dijkstra(h,i) << ' ' << dijkstra(s,i) << '\n';
            int si = dijkstra(s,i);
            if(sg + gh + dijkstra(h,i) == si || sh + hg + dijkstra(g,i) == si){
                cout << i+1 << ' ';
            }
        }
    }
    cout << '\n';
}
}