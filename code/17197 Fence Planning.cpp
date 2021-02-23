// date: Tue Feb 23 21:37:54 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

vector<pii> nodes((int)1e5+5);
vector<int> adj[(int)1e5+5];
bool vis[(int)1e5+5];

int mnx,mxx,mny,mxy;
int dfs(int curr){
	if(vis[curr]) return 0;
	vis[curr] = 1;

	int x = nodes[curr].first;
	int y = nodes[curr].second;
	
	mnx = min(mnx,x);
	mxx = max(mxx,x);
	mny = min(mny,y);
	mxy = max(mxy,y);

	for(auto next: adj[curr]){
		if(!vis[next]){
			dfs(next);
		}
	}
	return ((mxx-mnx)+(mxy-mny)) *2;
}

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M;
	cin >> N >> M;
	for(int i=0; i < N; i++){
		int x,y; cin >> x >> y;
		nodes[i] = {x,y};
	}
	for(int i=0; i< M; i++){
		int u,v; cin >> u >> v ;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 2e9;
	for(int i=0; i< N; i++){
		if(!vis[i]){
			mnx = 2e9; mxx = 0; mny = 2e9; mxy=0;
			ans = min(ans,dfs(i));
		}
	}
	cout << ans;

}

