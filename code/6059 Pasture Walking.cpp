// date: Wed Feb 24 00:25:37 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int N,Q;
vector<pii> adj[1001];
bool vis[1001];
bool flag=false;
int dfs(int curr, int t, int S){
	// cout << S << ' ';
	if(curr == t) {
		flag=true;
		return S;
	}
	vis[curr] = true;
	for(auto next : adj[curr]){
		if(!vis[next.second]){
			int ret=0;
			ret = dfs(next.second,t,S+next.first);
			if(flag) return ret;
		}
	}
	return -1;
}
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N >> Q;
	for(int i=0; i< N-1; i++){
		int u,v,w; cin >> u >> v >> w; u--;v--;
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}
	for(int i=0; i< Q; i++){
		int a,b; cin >> a >> b; a--;b--;
		memset(vis,0,sizeof(vis));
		// dfs(a,b);
		// cout << i << endl;
		flag= false;
		cout << dfs(a,b,0) << '\n';
	}

}

