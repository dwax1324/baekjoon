// date: Sat Feb 20 01:38:52 2021
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

const int MAXN = 401, MAXV = MAXN*2+2, INF = 1e9;
int N,M;
vector<int>adj[MAXV];
int C[MAXV][MAXV], F[MAXV][MAXV], W[MAXV][MAXV];

struct mcmf{
	
	pii solve(int S, int E){
		int ret =0,tot=0;
		while(1){
			int prevv[MAXV],dist[MAXV],inQ[MAXV];
			fill(prevv,prevv+MAXV,-1);
			fill(dist,dist+MAXV,INF);
			fill(inQ,inQ+MAXV,0);
			queue<int> q;
			q.push(S);
			dist[S] = 0;
			inQ[S]= true;
			while(q.size()){
				int curr = q.front(); q.pop();
				inQ[curr] = false;
				for(auto next : adj[curr]){
					if(C[curr][next] - F[curr][next] >0 && dist[next] > dist[curr] + W[curr][next]){
						dist[next] = dist[curr] + W[curr][next];
						prevv[next] = curr;
						if(inQ[next] == false){
							inQ[next] = true;
							q.push(next);
						}
					}
				}
			}
			if(prevv[E] == -1) break;	
			for(int i=E; i!=S; i=prevv[i]){
				ret += W[prevv[i]][i];
				F[prevv[i]][i]++;
				F[i][prevv[i]]--;
			}
			tot++;
		}
		return {tot,-ret};
	}

}mcmf;
int32_t main(){α
	int S= MAXV-2, E = MAXV-1;
	cin >> N>> M;	
	for(int i=0; i < N; i++){
		C[S][i] =1;
		adj[S].push_back(i);
		adj[i].push_back(S);
	}
	for(int i=MAXN ;i < MAXN+M; i++){
		C[i][E]= 1;
		adj[E].push_back(i);
		adj[i].push_back(E);
	}

	for(int i=0; i < N ;i++){
		int t; cin >> t; while(t--){
			int v,w; cin >> v >> w; v--;
			v += MAXN;
			W[i][v] = -w;
			W[v][i] = w;
			C[i][v] = INF;
			adj[v].push_back(i);
			adj[i].push_back(v);
		}
	}

	pii a = mcmf.solve(S,E);
	cout << a.first << endl << a.second;

}

