// date: Sun Feb 21 17:00:50 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

const int MAXN = 1e6+1;
int N;

struct segtree{
	int tree[MAXN*4];
	segtree(){memset(tree,0,sizeof(tree));}

	int kth(int n, int l, int r, int t){
		if(l==r) return l;
		int mid = (l+r)/2;
		if(t <= tree[n*2]) return kth(n*2,l,mid,t);
		else return kth(n*2+1,mid+1,r,t-tree[n*2]);
	}
	void updt(int idx, int val, int n=1, int nl = 1, int nr = MAXN){
		if(idx < nl || idx> nr) return;
		tree[n] += val;
		if(nl == nr) return;
		int mid=(nl+nr)/2;
		updt(idx,val,n*2,nl,mid);
		updt(idx,val,n*2+1,mid+1,nr);
	}

}st;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	for(int i=0; i < N; i++){
		int a,b,c; cin >> a;
		if(a==1){
			cin >> b;
			int d=  st.kth(1,1,MAXN,b);
			cout << d << '\n';
			st.updt(d,-1);
		}else{
			cin >> b >> c;
			st.updt(b,c);
		}
	}

}

