// date: Mon Feb 15 15:10:07 2021
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
const int INF = 1<<30, MAXN = 1001;
vector<pii> adj[MAXN];
int dist[MAXN],vis[MAXN];
int N,M,X,Y;

void dijk(){
	fill(dist,dist+MAXN,INF);
	fill(vis,vis+MAXN,0);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,Y});
	dist[Y] = 0;
	while(pq.size()){
		int curr= pq.top().o2;  pq.pop();
		if(vis[curr]) continue;
		vis[curr] = true;
		for(auto x : adj[curr]){
			int next = x.o2, d = x.o1;
			if(dist[next] > dist[curr] + d){
				dist[next] = dist[curr] +d;
				if(!vis[next]) pq.push({dist[next],next});
			}
		}
	}

}

int32_t main(){ this_is_main_function
	cin >> N >> M >> X >> Y;
	for(int i=0; i < M; i++){
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({c,b});
		adj[b].push_back({c,a});
	}
	dijk();
	sort(dist,dist+MAXN);
	int cnt = 1;
	int dist_per_day = X;
	for(int i=0; i < N; i++){
		if(dist[i] *2 > X){
			cnt=-1;
			break;
		}
		if(dist_per_day < dist[i] * 2){
			cnt ++;
			i--;
			dist_per_day = X;
		}else{
		    dist_per_day -= dist[i]*2;
		}
	}
	cout << cnt;
}

