// date: Sat Feb 20 18:09:47 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int N,M;
const int MAXN = 1e6+1;
struct SEGTREE{
	int seg[MAXN*4];
	
	int init(int n=1, int nl=1, int nr=N){
		if(nl == nr ) return seg[n] = nl;
		int mid = (nl+nr)/2;
		return seg[n] = init(n*2,nl,mid)+init(n*2+1,mid+1,nr);
	}
	int query(int l, int r, int n =1, int nl =1, int nr=N){
		if(l > nr || r < nl) return 0;
		if(l <= nl && r >= nr) return seg[n];
		int mid = (nl+nr)/2;
		return query(l,r,n*2,nl,mid)+query(l,r,n*2+1,mid+1,nr);
	}

	int update(int idx, int val ,int n=1, int nl=1, int nr=N){
		if(idx < nl || idx > nr) return seg[n];
		if(nl == nr) return seg[n] = val;
		int mid= (nl +nr)/2;
		return seg[n] = update(idx,val,n*2,nl,mid)+update(idx,val,n*2+1,mid+1,nr);
	}

}st;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N>> M;
	// st.init();
	for(int i=0; i < M; i++){
		int a,b,c; cin >> a >> b >> c;
		if(a==0){
			cout << st.query(b,c) << '\n';
		}else{
			st.update(b,c);
		}

	}
}

