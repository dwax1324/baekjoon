// date: Wed Feb 24 02:04:29 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int T; cin >> T; for(int t=1; t<=T; t++){
	int N,M;
	cin >> N >> M;
	char mapp[1001][1001]={};
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			cin >> mapp[i][j];
	bool vis[1001][1001]={};
	int Q;
	cin >> Q;
	
	function<void(int,int)>dfs = [&](int r, int c){
		if(vis[r][c]) return;
		vis[r][c] =true;
		for(int d=0; d<4; d++){
			int nr = r + "2011"[d]-'1';
			int nc = c + "1102"[d]-'1';
			if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			if(mapp[nr][nc] != '1') continue;
			dfs(nr,nc);
		}
	};
	function<int()> cnt =  [&](){
		memset(vis,0,sizeof(vis));
		int ret=0;
		for(int i=0; i< N; i++)
			for(int j=0; j < M ; j++)
				 if(!vis[i][j] && mapp[i][j] == '1'){
					 ret++;
					 dfs(i,j);
				 }
		return ret;
	 };
	cout << "Case #" << t << ":\n";
	for(int i=0; i< Q; i++){
		char a; cin >> a;
		if(a== 'Q'){
			cout << cnt() << '\n';
		}else{
			int x,y,z; cin >> x >>y >>z;
			mapp[x][y] = (char)(z+'0');
		}
	}
}
}

