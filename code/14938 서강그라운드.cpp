// date: Mon Feb 15 12:41:24 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define this_is_main_function ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
// #define int int64_t

int N,M,R;
const int INF = 1<<30;
vector<int> items;
vector<pii> adj[101];
int dist[101],vis[101];
int dijkstra(int S){
	priority_queue<pii,vector<pii>,greater<pii>> q;
	fill(dist,dist+101,INF);
	memset(vis,0,sizeof(vis));
	q.push({0,S});
	dist[S]= 0;
	int ret= 0;
	while(q.size()){
		int curr =q.top().o2; q.pop();
		if(vis[curr]) continue;
		vis[curr] = true;
		ret += items[curr];
		for(auto p : adj[curr]){
			int next = p.o2, d = p.o1;
			if(dist[next] > dist[curr] + d && dist[curr] +d<= M ){
				dist[next] = dist[curr] + d;
				if(!vis[next]) q.push({dist[next],next});
			}
		}
	}
	return ret;
}



int32_t main(){ this_is_main_function
	cin >> N>> M >> R;
	items.resize(N);
	for(int i=0; i < N; i++) cin >> items[i];	
	for(int i=0; i < R; i++){
		int a,b,c; cin >> a >> b >> c;
		a--;b--;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}

	int ans = 0;
	for(int i=0; i < N; i++){
		ans = max(ans,dijkstra(i));
	}
	cout << ans;
}

