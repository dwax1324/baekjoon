// date: Wed Feb 24 03:04:46 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int dy[8] = {-2,-1,1,2,2,1,-1,-2};
int dx[8] = {1,2,2,1,-1,-2,-2,-1};

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M;
	cin >>M >> N;
	char mapp[151][151];
	queue<pii> q;
	bool vis[151][151];
	for(int i=0; i < N; i++){
		for(int j=0; j < M; j++){
			cin >> mapp[i][j];	
			if(mapp[i][j] == 'K'){
				q.push({i,j});
				vis[i][j] = 1;
			}
		}
	}
	for(int lev=0; q.size(); lev++){
		int qs = q.size();
		for(int i=0; i < qs; i++){
			int r = q.front().first, c = q.front().second; q.pop();
			if(mapp[r][c] == 'H') {cout << lev; exit(0);}
			for(int d=0; d < 8; d++){
				int nr = r + dy[d];
				int nc = c + dx[d];
				if(nr <0  || nc <0 || nr >= N || nc >= M) continue;
				if(mapp[nr][nc] == '*' || vis[nr][nc]) continue;
				q.push({nr,nc});
				vis[nr][nc] =1;
			}
		}
	}

}

