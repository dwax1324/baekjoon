// date: Mon Feb 15 23:48:36 2021
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

int N,M;
int dist[101][101];
const int INF= 1<<25;
int32_t main(){ this_is_main_function
	cin >> N>> M;
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			dist[i][j] = (i==j ? 0 : INF);

	for(int i=0; i < M; i++){
		int u,v ; cin >> u >> v; u--;v--;
		dist[u][v] = 1;
	}
	
	for(int k=0; k < N; k++)
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
	for(int i=0; i < N; i++){
		int temp =0;
		for(int j=0; j < N; j++)
			if(dist[i][j] == INF && dist[j][i] == INF) temp++;
		cout << temp << endl;
	}
}

