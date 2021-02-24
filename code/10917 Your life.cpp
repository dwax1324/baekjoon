// date: Wed Feb 24 00:06:51 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector<int> adj[100001];
	for(int i=0; i < M; i++){
		int u,v; cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
	}
	queue<int> q;
	bool vis[100001]= {};
	q.push(0);
	vis[0]= true;

	for(int lev=0; q.size(); lev++){
		int qs = q.size();
		for(int i=0; i< qs; i++){
			int curr = q.front(); q.pop();
			// cout << curr << ' ';
			if(curr == N-1) {cout << lev; exit(0);}
			for(auto next: adj[curr]){
				if(!vis[next]){
					vis[next] = true;
					q.push(next);
				}
			}
		}
	}
	cout << -1;
}

