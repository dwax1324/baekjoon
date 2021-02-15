// date: Mon Feb 15 13:22:46 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define this_is_main_function ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
// #define int int64_t

struct info{
	int cost,r,c;
	bool operator<(const info &a)const {
		return cost > a.cost;
	}
};
const int INF = 1<<30;
int mapp[1001][1001];
int dist[1001][1001],vis[1001][1001],N,M;

int32_t main(){ this_is_main_function
	cin >> N>> M;
	for(int i=0; i < N; i++){
		for(int j=0; j < M; j++){
			cin >> mapp[i][j];
			if(mapp[i][j] == -1) mapp[i][j] = INF/2;
		}
	}
	priority_queue<info>pq;
	for(int i=0; i < 1001; i++) fill(dist[i],dist[i]+1001,INF);
	dist[0][0] = mapp[0][0];
	pq.push({mapp[0][0],0,0});
	while(pq.size()){
		int r = pq.top().r, c = pq.top().c; pq.pop();
		if(vis[r][c]) continue;
		vis[r][c] = true;

		for(int d=0; d < 4 ;d++){
			int nr =  r+ "2011"[d]-'1';
			int nc =  c +"1102"[d]-'1';
			if(nr <0 || nc <0 || nr >= N || nc >= M) continue;
			if(dist[nr][nc] > dist[r][c] + mapp[nr][nc]){
				dist[nr][nc] = dist[r][c] + mapp[nr][nc];
				if(!vis[nr][nc]) pq.push({dist[nr][nc],nr,nc});
			}
		}
	}
	if(dist[N-1][M-1] >= INF/2) cout << -1;
	else cout << dist[N-1][M-1];
}

