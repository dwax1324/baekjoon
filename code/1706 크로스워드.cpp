// date: Tue Feb 23 23:23:21 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int N,M;
char mapp[21][21];
bool vis[21][21];

string dfs(int r, int c, int t){
	if(vis[r][c] || mapp[r][c] == '#' || r>=N || c >= M) return "";
	vis[r][c] = true;
	string ret="";
	ret += mapp[r][c];
	if(t == 0)
		ret+= dfs(r,c+1,t);
	if(t == 1)
		ret += dfs(r+1,c,t);
	return ret;
}
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N >> M;
	for(int i=0; i< N; i++)
		for(int j=0; j<M; j++)
			cin >> mapp[i][j];
	
	vector<string>ans;
	for(int i=0; i< N; i++)
		for(int j=0; j <M; j++)
			if(!vis[i][j] && mapp[i][j] != '#')
				ans.push_back(dfs(i,j,0));
	memset(vis,0,sizeof(vis));
	for(int i=0; i< N; i++)
		for(int j=0; j<M; j++)
			if(!vis[i][j] && mapp[i][j] != '#')
				ans.push_back(dfs(i,j,1));
	sort(all(ans));
	for(auto x : ans) if(x.size() >=2) {cout << x; break;}
}

