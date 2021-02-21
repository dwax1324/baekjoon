// date: Sun Feb 21 15:54:54 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int N,K;
const int MAXN=1e5+1,INF= 1e9;


struct SEGTREE{
	int mintree[MAXN*4],maxtree[MAXN*4];

	int mincons(int n=1, int nl=1, int nr=N){
		if(nl ==nr) return mintree[n] = nl;
		int mid = (nl+nr)/2;
		return mintree[n] = min(mincons(n*2,nl,mid),mincons(n*2+1,mid+1,nr));
	}
	int maxcons(int n=1, int nl=1, int nr=N){
		if(nl == nr) return maxtree[n] = nr;
		int mid = (nl+nr)/2;
		return maxtree[n] = max(maxcons(n*2,nl,mid),maxcons(n*2+1,mid+1,nr));

	}
	int minquery(int l, int r, int n=1, int nl = 1, int nr=N){
		if(l > nr || r < nl) return INF;
		if(l <= nl && r >= nr) return mintree[n];
		int mid = (nl+nr)/2;
		return min(minquery(l,r,n*2,nl,mid),minquery(l,r,n*2+1,mid+1,nr));
	}
	int maxquery(int l, int r, int n=1, int nl=1, int nr=N){
		if(l >nr || r < nl) return 0;
		if(l <= nl && r >= nr) return maxtree[n];
		int mid = (nl+nr)/2;
		return max(maxquery(l,r,n*2,nl,mid),maxquery(l,r,n*2+1,mid+1,nr));
	}
	int minupdate(int idx, int val, int n=1, int nl=1 ,int nr=N){
		if(idx < nl || idx > nr) return mintree[n];
		if(nl == nr) return mintree[n] = val;
		int mid = (nl+nr)/2;
		return mintree[n] = min(minupdate(idx,val,n*2,nl,mid),minupdate(idx,val,n*2+1,mid+1,nr));
	}
	int maxupdate(int idx,int val, int n=1, int nl=1, int nr =N){
		if(idx < nl || idx > nr) return maxtree[n];
		if(nl==nr) return maxtree[n] = val;
		int mid = (nl+nr)/2;
		return maxtree[n] = max(maxupdate(idx,val,n*2,nl,mid),maxupdate(idx,val,n*2+1,mid+1,nr));
	}

}st;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int T; cin >>T ;while(T--){
	cin >> N>> K;
	st.mincons();st.maxcons();
	for(int i=0; i < K; i++){
		int a,b,c; cin >> a >> b >> c;
		b++;c++;
		if( a==1){
			int L = st.minquery(b,c);
			int R = st.maxquery(b,c);
			if(L == b && R == c) cout << "YES\n";
			else cout << "NO\n";
		}else{
			int B = st.minquery(b,b);
			int C = st.minquery(c,c);
			st.minupdate(b,C);
			st.minupdate(c,B);
			st.maxupdate(b,C);
			st.maxupdate(c,B);
		}
	}
}
}

