// date: Mon Feb 15 14:28:19 2021
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

const int MAXN = 100001, INF = (1ll<<31) -1;
int M, N , NS, NA,NB;
vector<pii> adj[MAXN];
// NS -> NA -> NB  != NS -> NB -> NA 
// min(NS -> NA , NS -> NB) + NA- > NB  : since undirected graph && connected graph

int dijkstra(int S, int T){
	int dist[MAXN], vis[MAXN];
	fill(dist,dist+MAXN,INF);
	fill(vis,vis+MAXN,0);
	dist[S] = 0;
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,S});
	while(pq.size()){
		int curr = pq.top().o2, currd = pq.top().o1;pq.pop();
		if(vis[curr]) continue;
		vis[curr] = true;
		if(curr == T) return currd; 
		for(auto x : adj[curr]){
			int next = x.o2, d = x.o1;
			if(dist[next] > dist[curr]+ d){
				dist [next] = dist[curr] +d;
				if(!vis[next]) pq.push({dist[next],next});
			}
		}
	}
	return dist[T];
}


int32_t main(){ this_is_main_function
	cin >> M>> N >> NS >> NA >> NB;
	for(int i=0; i < M ; i++){
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}
	cout << min(dijkstra(NS,NA),dijkstra(NS,NB)) + dijkstra(NA,NB);
}

