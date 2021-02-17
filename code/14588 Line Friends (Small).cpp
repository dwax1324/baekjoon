// date: Tue Feb 16 02:35:48 2021
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

int N,Q;
const int INF = 1e9;
struct ifo{
	int l,r;
};
vector<ifo> V;
int dist[301][301];
int32_t main(){ this_is_main_function
	cin >> N;
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			dist[i][j] = (i==j ?0 : INF);
	for(int i=0; i < N; i++){
		int l,r; cin >> l >> r;
		V.push_back({l,r});
	}

	for(int i=0; i < N; i++){
		for(int j=0; j< N; j++){
			if(V[i].l > V[j].r || V[i].r < V[j].l ) continue;
				dist[i][j] = 1;
				dist[j][i] = 1;
		}
	}
	
	for(int k=0; k < N; k++)
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	cin >> Q;

	for(int i=0; i < Q; i++){
		int u,v; cin >> u >> v;u--;v--;
		cout << (dist[u][v]==INF ? -1 : dist[u][v])<< endl;
	}


}

