// date: Tue Feb 16 13:33:30 2021
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
#define int int64_t

int N,M;
bool con[1001];

struct disj{
	int pa[1001];
	disj(){
		for(int i=0; i < 1001; i++) pa[i] = i;
	}
	int find(int a) {return pa[a] = (pa[a] == a ? a : find(pa[a]));}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p ==q ) return false;
		pa[q] = p;
		return true;
	}
}disj;

vector<pii> v;

int sqr(int a) {return a*a;}
double calc(int a, int b){
	return sqrt(sqr(v[a].o1 - v[b].o1) + sqr(v[a].o2 - v[b].o2));
}

struct ifo{
	double dist;
	int a,b;
	ifo(double d_, int a_, int b_): dist(d_),a(a_),b(b_){}
	
	bool operator<(const ifo& a) const{
		return dist < a.dist;
	}
};

int32_t main(){ this_is_main_function
	cin >> N>> M;
	for(int i=0; i < N; i++){
		int a,b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	for(int i=0; i < M; i++){
		int a,b; cin >> a >> b; a--;b--;
		disj.uni(a,b);
	}
	vector<ifo> new_edges;
	for(int i=0; i < N; i++){
			for(int j=0; j < N; j++){
				if(i==j) continue;
				new_edges.push_back(ifo(calc(i,j),i,j));
			}
		}
	
	sort(all(new_edges));
	double ans=0;

	for(auto x : new_edges){
		if(disj.uni(x.a,x.b)) ans += x.dist;
	}

	cout << fixed << setprecision(2) << ans;

}

