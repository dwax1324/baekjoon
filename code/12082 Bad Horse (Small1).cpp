// date: Sun Feb 14 02:44:04 2021
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
const int MAXN = 505;

struct disj{
	int pa[MAXN], sz[MAXN];
	void init(int n){
		for(int i=0; i <= n; i++){
			pa[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x: find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p;
		sz[p] += sz[q];
		return 1;
	}
}disj;
int n;
int32_t main(){ this_is_main_function
int tt; cin >> tt ; for(int tc =1; tc<=tt; tc++){
	map<string,int> mp;
	cin >> n;
	int idx =0;
	vector<pii> v;
	for(int i=0; i < n; i++){
		string a,b;
		cin >> a >> b;
		if(mp.find(a) == mp.end()) mp[a] = ++idx;
		if(mp.find(b) == mp.end()) mp[b] = ++idx;
		v.push_back({mp[a],mp[b]});
	}
	disj.init(500);
	for(auto &i : v){
		disj.uni(i.first + idx, i.second);
		disj.uni(i.first , i.second+idx);
	}
	bool ans = true;
	for(int i=1; i<= idx; i++){
		if(disj.find(i) == disj.find(i+idx)){
			ans = false;
			break;
		}
	}
	printf("Case #%d: ", tc);
	ans ? puts("Yes") : puts("No");
}
}

