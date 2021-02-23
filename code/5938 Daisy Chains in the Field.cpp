// date: Tue Feb 23 22:47:14 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;



vector<int> adj[251];
vector<int> v;
bool vis[251];
void dfs(int curr){
	if(vis[curr]) return;
	vis[curr] = true;
	v.push_back(curr);
	for(auto next : adj[curr]){
		dfs(next);
	}
}

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M;
	cin >> N >> M;
	for(int i=0; i< M; i++){
		int u,v; cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<int> ans;
	for(int i=0; i< N; i++){
		if(!vis[i]){
			v={};
			dfs(i);
			bool con=false;
			for(auto x : v) if(x == 0) con=true;
			if(con) continue;
			for(auto x : v) ans.push_back(x);
		}
	}
	sort(all(ans));
	if(ans.size() == 0) cout << 0;
	else for(auto x : ans) cout << x+1 << '\n';
}

