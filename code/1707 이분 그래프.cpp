// date: Sat Feb 20 22:35:02 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int T; cin >> T; while(T--){
	vector<int> adj[20001];
	memset(adj,0,sizeof(adj));
	int N, M;
	cin >> N >> M;
	for(int i=0; i < M; i++){
		int u,v; cin >> u >> v; u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int color[20001];
	bool vis[20001];
	memset(color,-1,sizeof(color));
	memset(vis,0,sizeof(vis));
	bool ans = true;
	for(int i=0; i < N; i++){
		if(color[i] == -1){
			queue<int> q;
			q.push(i);
			color[i] = 1;
			// 1 for red, 0 for blue
			while(q.size()){
				int curr = q.front(); q.pop();
				for(auto next : adj[curr]){
					if(curr == next) { ans=false; goto bof;}
					if(color[next] == -1){
						if(color[curr] == 1) color[next] = 0;
						else color[next] =1;
						q.push(next);
					}
					if(color[curr] == color[next]){
						ans = false; goto bof;
					}
				}
			}
		}
	}
bof:
	if(ans) cout << "YES\n";
	else cout << "NO\n";
}
}

