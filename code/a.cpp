// date: Fri Feb 19 22:46:09 2021
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

const int MAXN = 20001, INF = 1e9;
struct edge{int v, w;};
int d[MAXN], inQ[MAXN], cnt[MAXN];
vector<edge> adj[MAXN];
deque<int> q;
int O,cK;

int32_t main(){α
	int N,M,K;
	cin >> N>> M>> K;
	O = cK = sqrt(N);
	for(int i=0; i < M ;i++){
		int u,v,w; cin >> u >> v >> w;
		adj[u].push_back({v,w});
	}
	fill(d,d+MAXN,INF);
	d[K] =0;
	q.push_back(K); inQ[K] = true;
	while(q.size()){
		int u = q.front(); q.pop_front(); inQ[u] = false;
		for(auto & e : adj[u]){
			int v = e.v, w= e.w;
			if( d[v] > d[u] + w){
				d[v] = d[u] + w;

				if(inQ[v] == 0){
					if(q.size() > 0 && d[q.back()] < d[q.front()]){
						q.push_front(q.back());
						q.pop_back();
					}
					int diff = INF;
					if(q.size()) diff = d[q.front()] - d[v];
					if(cnt[v] >= cK || diff >= 0) q.push_back(v), cnt[v]++;
					else q.push_front(v);
					inQ[v] = true;
				}
			}
		}

	}
	for(int i=1; i<= N; i++){
		if(d[i]>=INF) cout << "INF" << endl;
		else cout << d[i] << endl;
	}
}

