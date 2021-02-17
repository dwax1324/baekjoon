// date: Mon Feb 15 23:09:23 2021
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

int dp[501][501];
int N,M;
const int INF = 1<<26;

int cnt(int curr){
	vector<int> indegree;
	for(int i=0; i < N; i++){
		if(dp[curr][i] == INF) indegree.push_back(i);	
	}
	
	for(auto x : indegree){
		if( dp[x][curr] == INF) return false;
	}
	return true;
}

int32_t main(){ 
	cin >> N>> M;
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			dp[i][j] = (i==j ? 0 : INF);
	for(int i=0; i < M; i++){
		int u,v; cin >> u >> v; u--;v--;
		dp[u][v] =1;
	}
	
	for(int k=0; k < N; k++)
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	
	int ans =0;
	for(int i=0; i < N; i++){
		if(cnt(i)) ans++;
	}
	cout << ans;
}

