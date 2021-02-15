// date: Mon Feb 15 03:33:46 2021
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

const int MAXN = 100001, INF = 1ll<<62;
int N,M;
vector<pii> adj[MAXN];
int vis[MAXN],dist[MAXN];
bool ward[MAXN];

int dijkstra(){
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	memset(vis,0,sizeof(vis));
	fill(dist,dist+MAXN,INF);
	pq.push({0,0});
	dist[0] = 0;
	while(pq.size()){
		int curr = pq.top().o2; pq.pop();
		if(vis[curr]) continue;
		vis[curr]= true;

		for(auto p : adj[curr]){
			int next = p.o2 , d = p.o1;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] +d;
				if(!vis[next]) pq.push({dist[next],next});
			}
		}
	}
	return (dist[N-1] == INF ? -1 : dist[N-1]);
}


int32_t main(){ this_is_main_function
	cin >> N >> M;
	for(int i=0; i < N; i++) cin >> ward[i];
	ward[N-1] = 0;
	for(int i=0; i < M ;i++){
		int a,b,c; cin >> a >> b >> c;
		if(!ward[a] && !ward[b]){
			adj[a].push_back({c,b});
			adj[b].push_back({c,a});
		}
	}
	cout << dijkstra();

}

