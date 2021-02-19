// date: Wed Feb 17 14:56:10 2021
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
int N,C;
int sqr(int a) {return a*a;}
struct E{
	int u,v,w;
	bool operator<(const E& a)const{
		return w < a.w;
	}
};
struct node{
	int x,y;
};
struct disj{
	int pa[2001];
	disj(){
		for(int i=0; i < 2001; i++) pa[i] = i;
	}
	int find(int x){
		if(pa[x] == x) return x;
		return pa[x]=find(pa[x]);
	}
	bool uni(int a,int b){
		a= find(a); b = find(b);
		if(a==b) return false;
		pa[b] = a; return true;
	}
}disj;
vector<node> nodes;
vector<E>edges;
int get_dist(int a, int b){
	return sqr(nodes[a].x-nodes[b].x) + sqr(nodes[a].y- nodes[b].y);
}
int32_t main(){ this_is_main_function
	cin >> N >> C;
	for(int i=0; i < N; i++){
		int a,b; cin >> a >> b;
		nodes.push_back({a,b});
	}
	for(int i=0; i < N; i++)
		for(int j=i+1; j < N; j++)
			edges.push_back({i,j,get_dist(i,j)});
	
	sort(all(edges));
	int tot=0,cnt=0;
	for(auto &x : edges){
		if(disj.find(x.u) == disj.find(x.v) || x.w < C){
			continue;
		}
		disj.uni(x.u,x.v);
		cnt++;
		tot += x.w;
	}
	if(cnt == N-1) cout << tot;
	else cout << -1;
}

