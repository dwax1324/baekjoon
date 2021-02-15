// date: Sun Feb 14 15:07:28 2021
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

struct disj{
	int pa[300001];
	void init(int n){
		for(int i=0; i <= n; i++)
			pa[i] =i;
	}
	int find(int x){return pa[x] = (pa[x] == x ? x : find(pa[x]));}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q ) return false;
		pa[q] = p;
		return true;
	}
}disj;


int32_t main(){ this_is_main_function
	int n; cin >> n;
	disj.init(n);
	for(int i=0; i < n-2; i++){
		int a,b; cin >> a >> b; a--;b--;
		disj.uni(a,b);	
	}
	set<int> st;
	for(int i=0; i <n ; i++){
		st.insert(disj.find(i));
	}
	for(auto x : st) cout << x+1 << ' ';

}

