// date: Sat Feb 20 03:52:31 2021
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
const int MAXN = 501, MAXV = 501+2,S=MAXV-2,E=MAXV-1,INF=1e9;

int N, C[MAXV][MAXV],F[MAXV][MAXV];
int level[MAXV];
int work[MAXV];
vector<int> adj[MAXV];

struct DINIC{
	bool bfs(){
		fill(level, level+MAXV, -1);
		level[S] = 0;
		queue<int> q;
		q.push(S);
		while(q.size()){
			int curr = q.front(); q.pop();
			for(auto next : adj[curr]){
				if(level[next] == -1 && C[curr][next]-F[curr][next]>0){
					level[next] = level[curr] +1;
					q.push(next);
				}
			}
		}
		return level[E] != -1;
	}

	int dfs(int curr, int dest, int flow){
		if(curr == dest) return flow;
		for(int &i= work[curr]; i< adj[curr].size(); i++){
			int next = adj[curr][i];
			if(level[next] == level[curr]+1 && C[curr][next]-F[curr][next] > 0){
				int df = dfs(next,dest,min(C[curr][next]-F[curr][next],flow));
				if(df>0){
					F[curr][next] += df;
					F[next][curr] -= df;
					return df;
				}
			}
		}
		return 0;
	}


	


	int solve(){
		int ret=0;
		while(bfs()){
			fill(work,work+MAXV,0);
			while(1){
				int flow = dfs(S,E,INF);
				if(flow == 0) break;
				ret += flow;
			}
		}
		return ret;
	}

}dinic;


int32_t main(){α
	cin >> N;
	for(int i=0; i < N; i++){
		int team; cin >> team;
		if(team == 1){
			C[S][i] = INF;
			adj[S].push_back(i);
			adj[i].push_back(S);
		}else if(team == 2){
			C[i][E] = INF;
			adj[i].push_back(E);
			adj[E].push_back(i);
		}
	}
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			cin >> C[i][j];
			if(i != j) adj[i].push_back(j);
		}
	}
	cout << dinic.solve() << endl;

	bool vis[MAXV] = {0};
	vis[S] = true;
	queue<int> q;
	q.push(S);
	while(q.size()){
		int curr = q.front(); q.pop();
		for(auto next : adj[curr]){
			if(vis[next] == 0 && C[curr][next] -F[curr][next] > 0){
				vis[next] = true;
				q.push(next);
			}
		}
	}
	for(int i=0; i < N; i++)
		if(vis[i]) cout << i+1 << ' ';
	cout << endl;
	for(int i=0; i < N; i++)
		if(!vis[i]) cout << i+1 << ' ';
	cout << endl;

	

}

