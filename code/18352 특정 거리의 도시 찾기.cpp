// date: Tue Feb 23 14:22:33 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M,K,X;
	cin >> N >> M >> K >> X;
	vector<int>adj[(int)3e5+1];
	for(int i=0; i< M; i++){
		int u,v; cin >> u >> v; u--;v--;
		adj[u].push_back(v);
	}

	X--;
	bool vis[(int)3e5+1] ={0};
	queue<int>q;
	vis[X]= true;
	q.push(X);
	multiset<int> ss;
	for(int lev=0; lev!=K+1;lev++){
		int qs= q.size();
		for(int i=0; i < qs; i++){
			int curr = q.front(); q.pop();
			if(lev == K) ss.insert(curr+1); 
			for(auto next: adj[curr]){
				if(!vis[next]){
					q.push(next);
					vis[next]= true;
				}
			}
		}
	}
	if(ss.size() == 0) {cout << -1; exit(0);}
	for(auto x : ss) cout << x << '\n';
}

