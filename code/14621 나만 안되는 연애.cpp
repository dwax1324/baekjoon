// date: Wed Feb 17 10:17:39 2021
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

struct disj{
	int pa[1001];
	disj(){
		for(int i=0; i < 1001; i++) pa[i] =i;
	}
	int find(int a){ return pa[a] = (pa[a] == a ? a : find(pa[a]));}
	bool uni(int a, int b){
		a = find(a); b = find(b);
		if(a== b) return false;
		pa[b] = a;
		return true;
	}
}disj;

struct E{
	int u,v,w;
	bool operator<(const E& a) const{
		return w < a.w;
	}
};
vector<E> edges;

int sex[1001];
int32_t main(){ this_is_main_function
	cin >> N>> M; 
	for(int i=0; i < N; i++) {char a;cin>>a;
		if(a=='W') sex[i] =1;
	}
	for(int i=0; i < M; i++){
		int u,v,w; cin >> u >> v >> w; u--;v--;
		if(sex[u] != sex[v])
			edges.push_back({u,v,w});
	}
	sort(all(edges));
	int cnt=0,ans=0;
	for(auto x : edges){
		if(disj.uni(x.u,x.v)){
			cnt++; ans += x.w;
		}
	}
	if(cnt == N-1) cout << ans;
	else cout << -1;
}


