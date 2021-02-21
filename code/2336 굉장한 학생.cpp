// date: Sun Feb 21 19:08:34 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int N;
const int INF = 1e9;
const int MAXN = 5e5+1;
struct score{
	int a,b,c;
};

score scoreArr[MAXN];
struct segtree{
	int tree[MAXN*4];

	int query(int l, int r, int n=1, int nl=1, int nr=N){
		if(l > nr || r <nl) return INF;
		if(l <= nl && r >= nr) return tree[n];
		int mid = (nl+nr) /2;
		return min(query(l,r,n*2,nl,mid),query(l,r,n*2+1,mid+1,nr));
	}
	int updt(int idx, int val, int n=1, int nl=1, int nr=N){
		if(idx < nl || idx > nr) return tree[n];
		if(nl==nr) return tree[n] = val;
		int mid = (nl+nr) /2;
		return tree[n]=min(updt(idx,val,n*2,nl,mid),updt(idx,val,n*2+1,mid+1,nr));
	}
}st;
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	for(int i=1; i <= N; i++){ int x; cin >> x; scoreArr[x].a = i;}
	for(int i=1; i <= N; i++){ int x; cin >> x; scoreArr[x].b = i;}
	for(int i=1; i <= N; i++){ int x; cin >> x; scoreArr[x].c = i;}
	sort(scoreArr+1,scoreArr+1+N,[](score a, score b){
		return a.a < b.a;
	});
	for(int i=1; i <= N; i++){
		st.updt(i,INF);
	}
	int ans=0;
	for(int i=1; i<= N; i++){
		if(st.query(1,scoreArr[i].b) > scoreArr[i].c) ans++;
		st.updt(scoreArr[i].b,scoreArr[i].c);
	}
	cout << ans;

}

