// date: Fri Feb 19 21:09:05 2021
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

const int MAXN = 6401;
vector<int> adj[MAXN];
const int roff[6] = {-1, 0, 1, -1, 0, 1};
const int coff[6] = {-1, -1, -1, 1, 1, 1};
struct bm{
	int A[MAXN],B[MAXN],vis[MAXN];
	void init(){
		for(int i=0; i < MAXN; i++) A[i] = B[i] = -1;
	}
	void rsvis(){ memset(vis,0,sizeof(vis));}
	bool dfs(int a){
		if(vis[a]) return false;
		vis[a] = true;
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

int f(int i, int j){
	return i * 80 + j;
}
int32_t main(){α
int T; cin >> T; while(T--){
	int N, M ; cin >> N >> M;
	char mapp[81][81];
	int tot=0;
	memset(mapp,0,sizeof(mapp));
	memset(adj,0,sizeof(adj));
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++){
			cin >> mapp[i][j];
			tot += mapp[i][j] == '.';
		}

	for(int j=0; j < M; j++){
		for(int i=0; i < N; i++){
			if(mapp[i][j] == 'x') continue;	
			int curr = f(i,j);

			for(int d= 0; d < 6; d++){
				int nr = i + roff[d];
				int nc = j + coff[d];
				if(nr <0 || nc <0 || nr >= N || nc >= M || mapp[nr][nc] == 'x') continue;
				adj[curr].push_back(f(nr,nc));
			}
		}
	}
	
	int ans=0;
	bm.init();
	for(int i=0; i < N; i++){
		for(int j=0; j < M; j+=2){
			if(mapp[i][j] == 'x') continue;
			bm.rsvis();
			ans += bm.dfs(f(i,j));
		}
	}
	cout << tot-ans << endl;
}
}

