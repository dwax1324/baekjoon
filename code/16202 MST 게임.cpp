// date: Wed Feb 17 12:02:33 2021
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

int N,M,K;
struct edge{
	int u,v,w;
	bool operator<(const edge &a ) const{
		return w < a.w;
	}
};
struct disj{
	int pa[1001];
	void init(){
		for(int i=0; i < 1001; i++) pa[i] = i;
	}
	int find(int a) { return pa[a] = (a == pa[a] ?a : find(pa[a]));}
	bool uni(int a, int b){
		a = find(a); b = find(b);
		if(a==b) return false;
		pa[b] = a;
		return true;
	}

}disj;
deque<edge>edges;
int32_t main(){ this_is_main_function
	cin >> N >> M >> K;
	for(int i=0 ; i < M; i++){
		int u,v; cin >> u >> v; u--;v--;
		edges.push_back({u,v,i+1});
	}
	sort(all(edges));
	for(int i=0; i < K; i++){
		disj.init();
		int conn = 0,ans=0;
		for(auto x : edges){
			if(disj.uni(x.u,x.v)){
				conn++;
				ans += x.w;
				if(conn == N-1) break;
			}
		}
		if(conn == N-1){
			cout << ans << ' ';
			edges.pop_back();
		}
		else cout << 0 << ' ';
	}



}

