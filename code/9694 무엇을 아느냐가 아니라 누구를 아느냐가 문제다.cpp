// date: Mon Feb 15 13:51:10 2021
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

int N,M;
const int INF = 1<<30;
vector<pii> adj[21];
int dist[21],vis[21],parent[21];

bool dijkstra(){
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	dist[0] = 0;
	pq.push({0,0});
	
	while(pq.size()){
		int curr=  pq.top().o2; pq.pop();
		if(vis[curr]) continue;
		vis[curr]=  true;
		for(auto x : adj[curr]){
			int next = x.o2, d = x.o1;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr]+d;
				if(!vis[next]) {
				 parent[next] = curr;
					pq.push({dist[next],next});
				}
			}
		}
	}
	return (dist[N-1] == INF ?0 : 1);
}

void print_path(int curr){
	if(parent[curr] == -1){
		cout << curr << ' ';
		return;
	}
	print_path(parent[curr]);
	cout << curr << ' ';
}


int32_t main(){ 
int tt; cin >> tt; for(int tc=1; tc<= tt; tc++){
	cin >> M >> N;
	for(int i=0; i < 21; i++){
		adj[i].clear();
		dist[i] = INF; vis[i] = 0;parent[i] =-1;
	}
	for(int i=0; i < M; i++){
		int a,b,c;
		cin >> a >> b >> c;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}
	if(dijkstra()){
		printf("Case #%d: ",tc);
		print_path(N-1);
		puts("");
	}else{
		printf("Case #%d: -1\n",tc);
	}

}
}

