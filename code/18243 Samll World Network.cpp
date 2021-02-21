// date: Sat Feb 20 05:48:58 2021
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
const int INF = 1e9;
int32_t main(){α
	int N,M; cin >> N>> M;
	int dist[101][101];
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			dist[i][j] = i==j ? 0 : INF;
	for(int i=0; i < M; i++){
		int u,v; cin >> u >> v;u--;v--;
		dist[u][v]=dist[v][u]=1;	
	}
	for(int k=0; k< N; k++)
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
	bool ans = true;
	for(int i=0; i < N; i++){
		for(int j=0;j < N;j++){
			if(dist[i][j]>6) ans= false;
		}
	}
	if(ans) cout << "Small World!";
	else cout << "Big World!";

}

