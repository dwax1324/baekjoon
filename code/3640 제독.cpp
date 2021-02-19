// date: Sat Feb 20 02:14:13 2021
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

const int MAXN = 1001, MAXV = MAXN*2+2, INF = 1e9;
int N,M;
vector<int> adj[MAXV];
int C[MAXV][MAXV],F[MAXV][MAXV],W[MAXV][MAXV];

struct MCMF{
	int solve(int S, int E){
		int ret= 0,T=0;
		while(T++ != 2){
			int prevv[MAXV],dist[MAXV],inQ[MAXV];
			memset(prevv,-1,sizeof(prevv));
			memset(inQ,0,sizeof(inQ));
			fill(dist,dist+MAXV,INF);
			queue<int> q;
			q.push(S); dist[S] =0; inQ[S]= true;
			while(q.size()){
				int curr=  q.front(); q.pop();
				inQ[curr] = false;
				for(auto next : adj[curr]){
					if(C[curr][next] - F[curr][next] >0 && dist[next] > dist[curr] + W[curr][next]){
						dist[next] =dist[curr] + W[curr][next];
						prevv[next] = curr;
						if(inQ[next] == false){
							inQ[next] = true;
							q.push(next);
						}
					}
				}
			}
			for(int i=E; i!=S; i= prevv[i]){
				ret += W[prevv[i]][i];
				F[prevv[i]][i]++;
				F[i][prevv[i]]--;
			}
		}
		return ret;
	}
}mcmf;
int32_t main(){α
	
while(cin >> N >> M){
	for(int i=0; i < MAXV; i++){
		adj[i].clear();
		for(int j=0; j< MAXV;j++)
			F[i][j]=C[i][j]=W[i][j]=0;
	}
	for(int i=0; i < N; i++){
		int u = i*2, v= i*2+1;
		C[u][v] =1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=0; i < M; i++){
		int u,v,w; cin >> u >> v >> w; u--;v--;
		int u1= u*2, u2 = u*2+1;
		int v1= v*2, v2 = v*2+1;
		W[u2][v1] = w;
		W[v1][u2] = -w;
		C[u2][v1] = 1;
		adj[u2].push_back(v1);
		adj[v1].push_back(u2);
	}

	cout << mcmf.solve(1,(N-1)*2) << endl;
}
}

