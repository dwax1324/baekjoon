// date: Sun Feb 14 14:18:13 2021
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
const int MAXN = 3001;
struct enmy{
	double c,r,R;
}emny;
struct disj{
	int pa[MAXN],sz[MAXN];
	void init(int n){
		for(int i=0; i <= n; i++){
			pa[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p ==q) return false;
		pa[q] = p;
		sz[p] += sz[q];
		return true;
	}
}disj;

vector<enmy> v;
double sqr(double a){ return a*a ;}
double get_dist(enmy p, enmy q){
	return sqrt(sqr(p.r-q.r)+sqr(p.c-q.c));
}
int32_t main(){ this_is_main_function
int tc; cin >> tc; while(tc--){
	int n; cin >> n;
	v={};
	for(int i=0; i < n; i++){
		double c,r,R;
		cin >> c >> r >> R;
		v.push_back({c,r,R});
	}
	disj.init(3000);

	for(int i=0; i < n; i++){
		for(int j=i+1; j< n; j++){
			enmy a = v[i], b = v[j];
			double d = get_dist(a,b);
			// if the circle is not in the outside
			if(a.R+b.R >= d)
				disj.uni(i,j);
		}
	}
	set<int> s;
	for(int i=0; i < n; i++){
		s.insert(disj.find(i));
	}
	cout << s.size() << endl;

}
}
