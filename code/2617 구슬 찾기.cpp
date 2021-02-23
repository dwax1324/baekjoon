// date: Tue Feb 23 14:52:39 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

vector<int>adj[100];
vector<int>adj2[100];

int bfs(int x, int t){
	bool vis[101]={0};
	queue<int> q;
	q.push(x);
	vis[x] = true;
	int ret=0;
	for(;q.size();){
		int qs = q.size();
		for(int i=0; i < qs; i++){
			int curr= q.front(); q.pop();
			for(auto next : (t== 0 ? adj[curr] : adj2[curr])){
				if(!vis[next]){
					ret++;
					vis[next] = true;
					q.push(next);
				}
			}
		}
	}
	return ret;
}

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M;
	cin >> N>>M;
	int piv = (N)/2;
	for(int i=0; i< M; i++){
		int u,v; cin >> u >> v; u--;v--;
		adj[u].push_back(v);
		adj2[v].push_back(u);
	}
	int ans=0;	
	for(int i=0; i < N; i++){
		ans += (bfs(i,0) > piv);
	}
	for(int i=0; i < N; i++){
		ans += (bfs(i,1) >piv);
	}
	cout << ans;
}

