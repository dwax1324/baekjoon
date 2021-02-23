// date: Tue Feb 23 03:04:31 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int t; cin >> t ; while(t--){
	int N,M; cin >> N>> M;
	vector<int> adj[101];
	for(int i=0; i < M; i++){
		char a; int u,v;
		cin >> a >> u;
		cin >> a >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	char a; int s; cin >> a >> s;
	// cout << s << '\n';
	queue<int> q;
	int vis[101]={0};
	q.push(s);
	vis[s] = true;
	int cnt=0;
	for(int l=0;l<3;l++){
		int qs = q.size();
		cnt += qs;
		for(int i=0; i < qs; i++){
			int curr= q.front(); q.pop();
//			cout << curr << ' ';
			for(auto next :  adj[curr]){
				if(!vis[next]) {
					vis[next]=true;
					q.push(next);
				}
			}
		}
	}
	printf("The number of supervillains in 2-hop neighborhood of v%d is %d\n",s,cnt-1);
}
}

