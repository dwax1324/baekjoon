// date: Sun Feb 21 13:57:31 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


const int MAXN = 1e5+1;
int N,M;

struct SEGTREE{
	int seg[MAXN*8];
	void init(){memset(seg,0,sizeof(seg));}
	int query(int l, int r){ return query(l,r,1,1,N+M); }
	int query(int l, int r, int n, int nl, int nr){
		if(l > nr || r < nl) return 0;
		if(l <= nl && r >= nr) return seg[n];
		int mid = (nl+nr)/2;
		return query(l,r,n*2,nl,mid)+query(l,r,n*2+1,mid+1,nr);
	}
	int update(int idx, int val){return update(idx,val,1,1,N+M);}
	int update(int idx, int val, int n, int nl, int nr){
		if(idx < nl || idx > nr) return seg[n];
		if(nl == nr) return seg[n] += val;
		int mid = (nl+nr)/2;
		return seg[n]=update(idx,val,n*2,nl,mid)+update(idx,val,n*2+1,mid+1,nr);
	}
}st;
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int T; cin >> T; while(T--){
	cin >> N>> M;
	st.init();
	int index[(int)1e5+1];
	for(int i=1; i<= N; i++){
		index[i] = N-i;
		st.update(index[i],1);
	}
	for(int i=1; i <= M; i++){
		int a; cin >> a;
		cout << st.query(index[a]+1,N+M) << ' ';
		st.update(index[a],-1);
		index[a] = N+i;
		st.update(index[a],1);
	}
	cout << '\n';
}
}

