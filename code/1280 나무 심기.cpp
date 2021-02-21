// date: Sun Feb 21 00:39:45 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;
int N; 
const int MAXN = 200001,MOD = 1e9+7;
int dist[MAXN];
struct segtree{
	struct node{
		int val,cnt;
		node(int val1=0, int cnt1=0):val(val1),cnt(cnt1){};
		node operator = (const node& a){
			this->val = a.val;
			this->cnt = a.cnt;
			return *this;
		}
		node operator + (const node& a){
			return node(this->val + a.val,  this->cnt + a.cnt);
		}
	};
	node seg[MAXN*4];
	node update(int idx, int n, int nl, int nr){
		if(idx < nl || idx > nr) return seg[n];
		if(nl == nr) return seg[n] = seg[n] + node(idx,1);
		int mid = (nl+nr)/2;
		return seg[n] = update(idx,n*2,nl,mid)+update(idx,n*2+1,mid+1,nr);

	}
	node query(int n, int l, int r, int nl, int nr){
		if(l > nr || r < nl) return node(0,0);
		if(l <=nl && r >= nr) return seg[n];
		int mid = (nl+nr)/2;
		return query(n*2,l,r,nl,mid)+query(n*2+1,l,r,mid+1,nr);
	}
}st;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	int res=0;
	for(int i=1; i <= N; i++){
		int k;cin >> k;
		if(i==1) { st.update(k,1,0,MAXN); continue;}
		
		segtree::node left = st.query(1,0,(k-1<0?0:k-1),0,MAXN);
		segtree::node right = st.query(1,(k+1>MAXN?MAXN:k+1),MAXN,0,MAXN);
		int q = (k*left.cnt - left.val + right.val - k* right.cnt)%MOD;
		res = (res*q)%MOD;
		st.update(k,1,0,MAXN);
	}
	cout << res;
		
}

