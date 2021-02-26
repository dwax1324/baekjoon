// date: Thu Feb 25 02:51:56 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

char mapp[51][51];

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M;
	cin >> N >> M;
	int r,c;	
	for(int i=0; i < N; i++){
		for(int j=0; j < M; j++){
			cin >> mapp[i][j];
			if(mapp[i][j] == 'X'){r=i;c=j;}
		}
	}
	bool vis[51][51] ={};
	function<void(int,int)> dfs = [&](int a, int b){
		if(vis[a][b]) return;	
		vis[a][b] = true;
		mapp[a][b] = 'O';
		for(int d=0; d<4; d++){
			int na = a + "2011"[d] -'1';
			int nb = b + "1102"[d] - '1';
			if(na < 0 || nb < 0 || na >= N || nb >= M) continue;
			if(mapp[na][nb] != 'X' || vis[na][nb]) continue;
			dfs(na,nb);
		}
	};
	dfs(r,c);
	
	function<int(int,int)> bfs = [&](int a, int b){
		queue<pii> q;
		bool vis[51][51]= {};
		vis[a][b] =1;
		q.push({a,b});
		for(int lev=0; q.size(); lev++){
			int qs = q.size();
			for(int i=0; i < qs; i++){
				int r = q.front().first, c = q.front().second; q.pop();
				if(mapp[r][c] == 'X') return lev;
				for(int d=0; d<4; d++){
					int nr = r + "2011"[d]-'1';
					int nc = c + "1102"[d]-'1';
					if(nr < 0  || nc < 0 || nr >= N || nc >= M) continue;
					if(vis[nr][nc] || mapp[nr][nc] == 'O') continue;
					q.push({nr,nc});
					vis[nr][nc] = true;
				}
			}
		}
		return 1<<30;
	};
	int ans= 1e9;
	for(int i=0; i < N; i++){
		for(int j=0; j< M; j++){
			if(mapp[i][j] == 'O') {
				ans= min(ans,bfs(i,j));
			}
		}
	}
	cout << ans-1;
}

