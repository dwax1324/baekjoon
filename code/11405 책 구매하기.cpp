// date: Fri Feb 19 23:31:51 2021
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

const int MAXN = 101, MAXV = 2*MAXN+2;
const int INF= 1e9;
int N,M;

int C[MAXV][MAXV];
int F[MAXV][MAXV];
int W[MAXV][MAXV];

vector<int> adj[MAXV];

struct mcmf{

}mcmf;


int32_t main(){α
	int S = MAXV-2, E = MAXV-1;
	cin >> N>> M;
	for(int i=MAXN; i < MAXN+N; i++){
		cin >> C[i][E];
		adj[E].push_back(i);
		adj[i].push_back(E);
	}

	for(int i=0; i < M; i++){
		cin >> C[S][i];
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for(int i=0; i < M; i++){
		for(int j=MAXN; j < MAXN + N; j++){
			cin >> W[i][j];
			W[j][i] = -W[i][j];
			C[i][j] = INF;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	int ret=0;
	while(1){
		int prevv[MAXV], dist[MAXV];
		bool inQ[MAXV] = {0};
		queue<int> q;
		fill(prevv,prevv+MAXV, -1);
		fill(dist, dist+MAXV, INF);
		dist[S] =0;
		inQ[S] = true;
		q.push(S);
		while(q.size()){
			int curr= q.front();q.pop();
			inQ[curr] = false;
			for(auto next : adj[curr]){
				if(C[curr][next] - F[curr][next] >0 && dist[next] > dist[curr] + W[curr][next]){
					dist[next] = dist[curr] +W[curr][next];
					prevv[next] = curr;
					if(!inQ[next]){
						q.push(next);
						inQ[next] = true;
					}
				}
			}
		}
		if(prevv[E] == -1) break;
		int flow = INF;
		for(int i=E; i!=S; i= prevv[i])
			flow = min(flow, C[prevv[i]][i] - F[prevv[i]][i]);
		for(int i=E; i!=S; i= prevv[i]){
			ret += flow * W[prevv[i]][i];
			F[prevv[i]][i] += flow;
			F[i][prevv[i]] -= flow;
		}

	}
	cout << ret;

}

