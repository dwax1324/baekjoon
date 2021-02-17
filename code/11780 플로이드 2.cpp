// date: Tue Feb 16 00:56:56 2021
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
const int INF = 1e9;
int dist[101][101],via[101][101];
vector<int> trace;
void solve(int S, int E){
	if(via[S][E] == -1) return;
	solve(S,via[S][E]);
	trace.push_back(via[S][E]);
	solve(via[S][E],E);
}

int32_t main(){ this_is_main_function
	cin >> N>> M;
	memset(via,-1,sizeof(via));
	for(int i=0; i < 101; i++)
		for(int j=0; j < 101;j++)
			dist[i][j] = (i==j ? 0 : INF);
	for(int i=0; i < M ;i++){
		int u,v,c; cin >> u >> v >> c;
		u--;v--;
		dist[u][v] = min(dist[u][v],c);
	}
	
	for(int k=0; k < N; k++)
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++){
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					via[i][j] = k;
				}
			}
	
	for(int i=0 ; i < N; i++){
		for(int j=0; j < N; j++){
			cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
		}
		cout << endl;
	}

	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			if(dist[i][j] == INF || i ==j) cout << 0 << endl;
			else{
				trace.clear();
				solve(i,j);
				cout << trace.size()+2 << ' ' << i+1 << ' ';
				for(auto &x : trace) cout << x+1 << ' ' ;
				cout << j+1 << endl;
			}
		}
	}

}
