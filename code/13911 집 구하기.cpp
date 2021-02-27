// date: Sat Feb 27 17:27:21 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

const int MAXN = 10003,INF = 2e9;
vector<pii> adj[MAXN];
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M; cin >> N>> M;
	// @ INPUT
	// @ edges
	for(int i=0; i < M; i++){
		int u,v,w; cin >> u >> v >> w; u--;v--;
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}
	// @ macdonald -> hub1
	int E2,X,E3,Y;
	cin >> E2 >> X;
	int hub1 = MAXN-1, hub2=MAXN-2;
	for(int i=0; i < E2; i++){
		int a; cin >> a ; a--;
		adj[hub1].push_back({0,a});
		adj[a].push_back({0,hub1});
	}
	// @ startbucks -> hub2
	cin >> E3 >> Y;
	for(int i=0; i < E3; i++){
		int a; cin >> a; a--;
		adj[hub2].push_back({0,a});
		adj[a].push_back({0,hub2});
	}

	// @ Func dijkstra
	auto dijk = [&](int start, int dist[MAXN]){
		priority_queue<pii,vector<pii>,greater<pii>> pq;
		bool vis[MAXN] = {0};
		fill(dist,dist+MAXN,INF);
		pq.push({0,start});
		dist[start]=0;
		while(pq.size()){
			int curr = pq.top().second; pq.pop();
			if(vis[curr]) continue;
			vis[curr] = true;
			for(auto x : adj[curr]){
				int next = x.second, d = x.first;
				if(dist[next] > dist[curr] + d){
					dist[next] = dist[curr]+d;
					if(!vis[next])
						pq.push({dist[next],next});
				}
			}
		}
	};

	// @ solve
	int dist1[MAXN], dist2[MAXN];
	dijk(hub1,dist1);
	// for(int i=0; i < N; i++) cout << dist1[i] << ' ';
	dijk(hub2,dist2);
	// cout << endl;
	// for(int i=0; i < N; i++) cout << dist2[i] << ' ';


	int ans =INF;
	for(int i=0; i < N; i++){
		// cout << i+1 << ' ' <<  dist1[i] << ' ' << dist2[i] << '\n';
		if(dist1[i] <= X && dist2[i] <= Y && (dist1[i] != 0 && dist1[i] != INF && dist2[i] != 0 && dist2[i] != INF)){
			ans= min(ans,dist1[i]+ dist2[i]);
		}
	}
	cout << (ans == INF ? -1 : ans);

}
