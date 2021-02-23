// date: Tue Feb 23 23:46:11 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;



char mapp[1001][1001];
bool vis[1001][1001];
int N;
void dfs(int r,int c){
	if(vis[r][c]) return;
	vis[r][c] = true;	
	for(int d=0; d<4; d++){
		int nr = r + "2011"[d]-'1';
		int nc = c + "1102"[d]-'1';
		if( nr < 0 || nc <0 || nr >= N || nc >= N) continue;
		if(mapp[nr][nc] == '*') continue;
		dfs(nr,nc);
	}
}


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	for(int i=0; i< N; i++)
		for(int j=0; j< N; j++)
			cin >> mapp[i][j];
	
	int cnt=0;
	for(int i=0; i< N; i++)
		for(int j=0; j< N; j++)
			if(!vis[i][j] && mapp[i][j] == '*')
			{dfs(i,j); cnt++;}
	cout << cnt;
}

