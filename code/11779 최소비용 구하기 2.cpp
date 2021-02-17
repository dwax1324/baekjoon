// date: Mon Feb 15 19:38:15 2021
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

const int MAX = 1001, INF = 1 << 30;
int N,M;
vector<pii> adj[MAX];
int vis[MAX],dist[MAX],prevv[MAX];

void dijk(int S, int T){
	priority_queue<pii,vector<pii>, greater<pii>> pq;
	fill(dist,dist+MAX,INF);
	dist[S] =0;
	pq.push({0,S});

	for(int i=0; i < N-1; i++){
		int curr = pq.top().o2; pq.pop();
		if(vis[curr]) continue;
		vis[curr]= true;
		for(auto x : adj[curr]){
			int next = x.o2, d = x.o1;
			if(dist[next] > dist[curr] + d){
				prevv[next] = curr;
				dist[next] = dist[curr] + d;
				if(!vis[next]) pq.push({dist[next],next});
			}
		}
		if(pq.size() ==0 ) break;
	}

}

int32_t main(){ this_is_main_function
	cin >> N >> M;

	for(int i=0; i < M; i++){
		int a,b,c; cin >> a >> b >> c;
		adj[a].push_back({c,b});
	}
	int S,T; cin >> S >> T;
	dijk(S,T);
	cout << dist[T] << endl;
	vector<int> res;
	for(int curr=T; curr != S; curr=prevv[curr]) res.push_back(curr);
	res.push_back(S);
	cout << res.size() << endl;
	for(int i= res.size()-1; i >= 0; i--){
		cout << res[i] << ' ';
	}
}

