// date: Wed Feb 17 08:23:37 2021
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
	void init (){
		for(int i=0; i < 1001; i++) pa[i] = i;
	}
	int find(int a) {return pa[a] = (pa[a] == a ? a : find(pa[a]));}
	bool uni(int a, int b){
		a = find(a);
		b = find(b);
		if(a==b) return false;
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
bool flag= false;
int solve(int X){
	disj.init();
	if(X==1){
		sort(all(edges),[](E a, E b){
			return a.w > b.w; 
		});
	}else sort(all(edges));
	disj.uni(0,1);	
	int ret = flag;
	for(auto &x : edges){
		if(disj.uni(x.u,x.v)){
			if(x.w == 0) ret++;
		}
	}
	return ret*ret;
}

int32_t main(){ this_is_main_function
	cin >> N >> M;
	for(int i=0; i < M+1; i++){
		int u,v,w;
		cin >> u >> v >> w;
		if(u == 0 && v == 1 && w == 0) flag = true;
		if(u == 1 && v == 0 && w == 0) flag = true;
		edges.push_back({u,v,w});
	}
	cout << abs(solve(0) - solve(1));
}

