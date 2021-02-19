// date: Wed Feb 17 12:40:04 2021
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

int N,M,T;
vector<pii>adj[10001];
int32_t main(){ this_is_main_function
	cin >> N>> M >> T;
	for(int i=0; i < M; i++){
		int u,v,w;
		cin >> u >> v >> w; u--;v--;
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}
	vector<int> vis(10001,0);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	pq.push({0,0});

	int t=-1,ret=0;
	while(pq.size()){
		int curr= pq.top().o2, w = pq.top().o1; pq.pop();
		if(vis[curr]) continue;
		vis[curr] = true;
		if( t > 0) ret += w + T*t;
		else ret += w;
		t++;
// 		cout << t << ' ' << endl;
// 		cout << curr << ' ' << w << ' ' << ret <<  endl;
		for(auto x : adj[curr]){
			int next = x.o2, next_w = x.o1;
			if(!vis[next]){
				pq.push({next_w,next});
			}
		}
	}
	cout << ret;
}

