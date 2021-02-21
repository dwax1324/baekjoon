// date: Sat Feb 20 05:37:01 2021
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

int32_t main(){α
	int N,M; cin >> N >> M;
	int mapp[301][301]={};
	bool vis[301][301]={};
	for(int i=0; i < N; i++)
		for(int j=0; j < M ;j++)
			cin >> mapp[i][j];
	queue<pii> q;
	q.push({0,0});
	vis[0][0] = true;
	int ans=0;
	for(;q.size();ans++){
		int qs = q.size();
		for(int i=0; i < qs; i++){
			int r = q.front().o1, c = q.front().o2; q.pop();
			if(r == N-1 && c == M-1) {
				cout << ans; exit(0);
			}
			for(int j=r+1; j <= r+mapp[r][c]; j++){
				if(j >=N) break;
				if(vis[j][c]) continue;
				q.push({j,c});vis[j][c]= true;
			}
			for(int j=c+1; j <= c+mapp[r][c]; j++){
				if(j >= M) break;
				if(vis[r][j]) continue;
				q.push({r,j});vis[r][j] = true;
			}
		}
	}


}

