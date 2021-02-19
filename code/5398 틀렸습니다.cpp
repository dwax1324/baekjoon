// date: Fri Feb 19 20:17:06 2021
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
		for(int i=0; i < MAXN; i++)
			A[i]=B[i]=-1;
	}
	void reset_vis(){ memset(vis,0,sizeof(vis)); }
	
	bool dfs(int a){
		if(vis[a]) return false;
		vis[a] = true;
		for(auto b : adj[a]){
			if(B[b] == -1 || dfs(B[b])){
				A[a]= b;
				B[b] =a;
				return true;
			}
		}
		return false;
	}
}bm;

int32_t main(){α
int T; cin >> T;while(T--){
	int N,M; cin >> N>> M;
	char mapp[1001][1001];
	int idx_mapp[1001][1001];
	bm.init();
	memset(mapp,0,sizeof(mapp));
	memset(idx_mapp,0,sizeof(idx_mapp));
	memset(adj,0,sizeof(adj));
	for(int i=0; i < N; i++){
		int c,r; cin >> c >> r;
		string s; cin >> s;
		for(int j=0; j<s.size(); j++){
			if(c+j > 1000) break;
			mapp[r][c+j] = s[j];
			idx_mapp[r][c+j] = i;
		}
	}
	
	for(int i=0; i < M; i++){
		int c,r; cin >> c >> r;
		string s; cin >> s;
		for(int j=0; j < s.size(); j++){
			if(r+j > 1000) break;
			if(mapp[r+j][c] != 0 && mapp[r+j][c] != s[j]){
				adj[idx_mapp[r+j][c]].push_back(i);	
			}
		}
	}
	
	int ans =N+M;
	for(int i=0; i < N; i++){
		bm.reset_vis();
		if(bm.A[i] == -1){
			ans -= bm.dfs(i);
		}
	}
	cout << ans << endl;
}
}

