// date: Mon Feb 15 02:46:27 2021
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

int N,D;
const int INF = 1<<30;
vector<pii> adj[10001];
int vis[10001];
int dist[10001];
int dijkstra(){
	priority_queue<pii,vector<pii>,greater<pii>> q;
	for(int i=0; i <= 10000; i++) dist[i] = INF;
	dist[0] = 0;
	q.push({0,0});
	
	while(q.size()){
		int curr = q.top().o2; q.pop();
		if(vis[curr]) continue;
		vis[curr] = true;

		for(auto p : adj[curr]){
			int next = p.o2 , d = p.o1;
			if(dist[next] > dist[curr] +  d){
				dist[next] = dist[curr] + d;
				if(!vis[next])
					q.push({dist[next],next});
			}
		}
	}
	return dist[D];
}


int32_t main(){ this_is_main_function
	cin >> N >> D;
	for(int i=0; i < D; i++){
		adj[i].push_back({1,i+1});
	}
	for(int i=0; i < N; i++){
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({c,b});
	}
	cout << dijkstra();

}

