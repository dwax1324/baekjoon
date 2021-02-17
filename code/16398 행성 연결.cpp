// date: Tue Feb 16 14:53:04 2021
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

int N;
struct ifo{
	int w,u,v;
	bool operator<(const ifo & a)const{
		return w < a.w;
	}
};
struct disj{
	int pa[1001];
	disj(){
		for(int i=0; i < 1001; i++) pa[i]= i;
	}
	int find(int a) {return pa[a] = (pa[a] == a ? a : find(pa[a]));}

	bool uni(int a, int b){
		a = find(a);
		b = find(b);
		if( a== b) return false;
		pa[b] = a;
		return true;
	}
}disj;
int32_t main(){ this_is_main_function
	cin >> N;
	vector<ifo> edges;
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			int a; cin >> a;
			if(i==j) continue;
			edges.push_back({a,i,j});
		}
	}
	sort(all(edges));
	int ans =0;	
	for(auto x : edges){
		if(disj.uni(x.u,x.v))ans += x.w;
	}
	cout << ans;
}

