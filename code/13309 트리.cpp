// date: Mon Feb 22 15:02:17 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


const int MAXN = (int)2e5;
struct disj{
	int pa[MAXN];
	disj(){
		for(int i=0; i< MAXN; i++)
			pa[i] = i;
	}
	int find(int x) { return pa[x] = (x == pa[x] ? x : find(pa[x]));}
	bool uni(int a, int b){
		a = find(a), b = find(b);
		if(a==b) return false;
		pa[b] = a;
		return true;
	}
}disj;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,Q,p[MAXN],q[MAXN*2][3];
	cin >> N>> Q;
	Q += N-1;
	for(int i=1; i< N; i++){
		cin >> p[i]; p[i]--;
	}
	for(int i=0; i < Q; i++){
		cin >> q[i][0] >> q[i][1];
		q[i][1]--;
		if(q[i][0] == 1){
			cin >> q[i][2];
			q[i][2]--;
		}
	}
	stack<bool>res;
	for(int i=Q-1; i>=0; i--){
		if(q[i][0] == 0) disj.uni(q[i][1],p[q[i][1]]);
		else{
			int u = disj.find(q[i][1]), v = disj.find(q[i][2]);
			res.push(u==v);
		}
	}
	while(res.size()){
		cout << (res.top() ? "YES" : "NO") << '\n';
		res.pop();
	}
}
