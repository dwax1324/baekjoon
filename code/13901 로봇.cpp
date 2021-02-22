// date: Tue Feb 23 02:12:27 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;



int dxy[4][2]={
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M,k;
	cin >> N >> M >> k;
	int mapp[1001][1001];
	bool vis[1001][1001];
	memset(mapp,0,sizeof(mapp));
	memset(vis,0,sizeof(vis));
	for(int i=0; i < k; i++){
		int a,b; cin >> a >> b;
		mapp[a][b] =1;
	}
	int sr, sc; cin >> sr >> sc;
	int dir[4];
	for(int d=0; d<4 ;d++) {cin >> dir[d]; dir[d]--;}

	
	int curd = 0;
	int r= sr, c = sc;
	int blocked=0;
	vis[r][c] = true;
	while(1){
		int dr = dxy[dir[curd]][0], dc = dxy[dir[curd]][1];
		int nr = r + dr, nc = c + dc;
		if(nr <0 || nc <0 || nr >= N || nc >= M || mapp[nr][nc] == 1 || vis[nr][nc]){
			curd++;
			curd %=4;
			blocked++;
		}else{
			blocked=0;
			vis[nr][nc] = true;
			r = nr; c = nc;
		}
		if(blocked>=10) break;
	}
	cout << r << ' ' << c;

}

