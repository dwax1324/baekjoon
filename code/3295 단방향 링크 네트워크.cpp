// date: Fri Feb 19 17:59:47 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define α ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
// #define int int64_t

const int MAXN = 1001;

vector<int> adj[MAXN];

struct bm{
	int A[MAXN],B[MAXN],vis[MAXN];
	void init(){
		for(int i=0; i < MAXN; i++) A[i]= B[i] = -1;
	}
	bm(){init();}
	void rsvis(){
		memset(vis,0,sizeof(vis));
	}
	bool dfs(int a){
		if(vis[a]) return false;
		vis[a]= true;
		for(auto b : adj[a]){
			if(B[b] == -1 || dfs(B[b])){
				A[a] = b;
				B[b] = a;
				return true;
			}
		}
		return false;
	}

}bm;

int32_t main(){α
int T; cin >> T; while(T--){
	int N,M; cin >> N>> M;
	memset(adj,0,sizeof(adj));
	bm.init();
	for(int i=0; i < M; i++){
		int u,v; cin>> u >> v;
		adj[u].push_back(v);
	}
	int ans=0;
	for(int i=0; i < N; i++){
		bm.rsvis();
		if(bm.A[i] == -1){
			if(bm.dfs(i)) ans++;
		}
	}
	cout << ans << endl;

}
}

