// date: Sun Feb 14 15:47:00 2021
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
const int MAX = 100001;
struct disj{
	int sz[MAX],pa[MAX];
	int find(int p) {
		if(p== -1) return -1;
		return pa[p] = (pa[p] == p ? p : find(pa[p]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p ==q) return false;
		pa[q] = p;
		sz[p] += sz[q];
		return true;
	}
	bool battle(int p, int q){
		p = find(p);
		q = find(q);
		if(p ==q) return false;
		if(sz[p] == sz[q]){
			pa[p] = -1;
			pa[q] = -1;
			sz[p] = 0;
			sz[q] = 0;
			return false;
		}
		if(sz[p] > sz[q]){
			sz[q] = -sz[q];
			uni(p,q);
		}else{
			sz[p] = -sz[p];
			uni(q,p);
		}
		return true;
	}
}disj;


int32_t main(){ this_is_main_function
	int N,M; cin >> N>> M;
	for(int i=0; i < N; i++){
		cin >> disj.sz[i];
		disj.pa[i] = i;
	}
	for(int i=0; i < M; i++){
		int o,p,q; cin >> o >> p >> q; p--;q--;
		if(o == 1) disj.uni(p,q);
		else{
			disj.battle(p,q);			
		}
	}
	set<pii> st;
	for(int i=0; i < N; i++){
		if(disj.find(i) != -1)
			st.insert({disj.sz[disj.find(i)],disj.find(i)});
	}
	cout << st.size() << endl;
    for(auto x : st) cout << x.first << ' ';
}

