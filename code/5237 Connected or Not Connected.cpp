// date: Wed Feb 24 03:30:51 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int T; cin >> T; while(T--){
	int N; cin >> N;
	int M; cin >> M;
	vector<int>adj[101];
	for(int i=0; i < M; i++){
		int u,v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	bool vis[101]={};
	function<int(int)> dfs = [&](int curr){
		vis[curr] = true;
		int ret=0;
		for(auto next : adj[curr]){
			if(!vis[next])
				ret += dfs(next)+1;
		}
		return ret;
	};
	int k = dfs(0);
	//cout << k << '\n';
	if( k+1 == N) cout << "Connected.\n";
	else cout << "Not connected.\n";
}
}

