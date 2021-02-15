// date: Mon Feb 15 03:05:56 2021
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
#define int int64_t


const int INF = 1<<30;
vector<pii> adj[101];
int dist[101],vis[101],dist_sum[101];

void dijkstra(int s){
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,s});
	fill(dist,dist+101,INF);
	memset(vis,0,sizeof(vis));
	dist[s] = 0;

	while(pq.size()){
		int curr = pq.top().o2; pq.pop();
		if(vis[curr]) continue;
		vis[curr] = true;
		for(auto p : adj[curr]){
			int next = p.o2, d = p.o1;
			if(dist[next] > dist[curr] + d){
				dist[next]  = dist[curr] +d;
				if(!vis[next]) pq.push({dist[next],next});
			}
		}
	}
	for(int i=1; i < 101; i++){
		dist_sum[i] += dist[i];
	}
}


int32_t main(){ this_is_main_function
int tt; cin >> tt ;while(tt--){
	int N,M; cin >> N>> M;
	for(int i=0; i < 101; i++){
		adj[i].clear();
		dist_sum[i] = 0;
	}
	for(int i=0; i < M; i++){
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}
	int K; cin >> K;
	memset(dist_sum,0,sizeof(dist_sum));
	for(int i=0; i < K; i++){
		int a; cin >> a;
		dijkstra(a);
	}
	int MIN = *min_element(dist_sum+1,dist_sum+101);
	for(int i=1; i < 101; i++){
		if(dist_sum[i] == MIN){
			cout << i << endl; break;
		}
	}
}
}

