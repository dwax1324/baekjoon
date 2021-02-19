// date: Wed Feb 17 13:52:12 2021
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
		for(int i=0; i < 1001; i++) pa[i]=i;
	}
	int find(int x) {return pa[x] = (x == pa[x] ? x : find(pa[x]));}
	bool uni(int a, int b){
		a = find(a); b = find(b);
		if(a==b) return false;
		pa[b] = a;
		return true;
	}
}disj;

struct E{
	int u,v,w;
	bool operator<(const E &a) const{
		return w < a.w;
	}
};
vector<E> edges;
bool all_conn(){
	for(int i=0; i < N-1; i++){
		if(disj.find(i)!=disj.find(i+1)) return false;
	}
	return true;
}
int32_t main(){ this_is_main_function
	cin >> N>> M;
	int u,v;
	for(int i=0; i < M; i++){
		cin >> u >> v;
		u--;v--;
		if(!u || !v) continue;
		disj.uni(u,v);
	}
	// for(int i=0; i < N; i++) cout << disj.pa[i] << ' ';
	// cout << endl;
	for(int i=0; i < N; i++)
		for(int j=0; j <N ;j++){
			int a; cin >> a;
			if(i == j || j==0 ) continue;
			if(i >= j) continue;
			edges.push_back({i,j,a});
		}
	sort(all(edges));
	int X =0;
	vector<pii> ans;
	for(auto x : edges){
		if(!x.u || !x.v) continue;
		if(disj.uni(x.u,x.v) == false) continue;
		X += x.w;
		ans.push_back({x.u,x.v});
	}
	cout << X << ' ' << ans.size() << endl;
	for(auto &x : ans) cout << x.o1+1 << ' ' << x.o2+1 << endl;
}

