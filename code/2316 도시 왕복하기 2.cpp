// date: Thu Feb 18 20:15:00 2021
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

const int MAXN=  401;
const int MAXV = MAXN*2+2;
const int INF = 1e9;

int N,P;

struct edge{
	int v,f,c;
	edge* rev;
	edge(int v1, int c1):v(v1),c(c1),f(0),rev(0){}
	void add_flow(int f1){
		f += f1;
		rev->f -=f1;
	}
	int spare(){ return c-f; }
};
vector<edge*>adj[MAXV];
struct mxf{
	void add_edge(int u, int v, int w){
		edge*e1 = new edge(v,w), *e2 = new edge(u,0);
		e1->rev = e2;
		e2->rev = e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}

	int solve(int S, int E){
		int ret =0;
		while(1){
			int prevv[MAXV];
			edge* path[MAXV]={0};
			fill(prevv,prevv+MAXV,-1);
			queue<int> q;
			q.push(S);
			while(q.size()){
				int curr = q.front(); q.pop();
				// cout << curr << endl;
				for(auto *e : adj[curr]){
					int next = e->v;
					if(prevv[next] == -1 && e->spare() > 0){
					// cout << next << ' ';
						q.push(next);
						path[next] = e;
						prevv[next] = curr;
						if(next == E) break;
					}
				}

			}
			if(prevv[E] == -1) break;
			int flow = INF;
			for(int i=E; i!= S; i= prevv[i])
				flow = min(flow, path[i]->spare());
			for(int i=E; i!= S; i= prevv[i])
				path[i]->add_flow(flow);
			ret+= flow;
		}
		return ret;
	}
}mxf;

int32_t main(){α
	cin >> N>> P;
	for(int i=0; i < N; i++){
		int u = i*2, v = i*2+1;
		if(i<=1) mxf.add_edge(u,v,INF);
		else mxf.add_edge(u,v,1);
	}
	for(int i=0; i < P; i++){
		int u,v; cin >> u >> v; u--;v--;
		mxf.add_edge(u*2+1,v*2,1);
		mxf.add_edge(v*2+1,u*2,1);
	}
//	for(int i=0; i < 10; i++){
//		cout << i << endl;
//		for(auto *e : adj[i]){
//			cout << e->v << ' ';
//		}
//		cout << endl;
//	}
	cout << mxf.solve(0,2);

}

