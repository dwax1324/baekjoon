// date: Mon Feb 22 14:34:02 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

const int MAX_ST = 1<<18;

struct MergesortTree{
	vector<int> arr[MAX_ST];
	void construct(){
		for(int i= MAX_ST/2-1; i>0 ; i--){
			vector<int> &c = arr[i], &l = arr[i*2], &r = arr[i*2+1];
			arr[i].resize(l.size()+r.size());
			for(int j=0,p=0,q=0; j < c.size(); j++){
				if(q == r.size() || (p < l.size() && l[p] < r[q])) c[j] = l[p++];
				else c[j] = r[q++];
			}
		}
	}

	int greater(int s, int e, int k, int node=1, int ns=0, int ne=MAX_ST/2){
		if(ne <= s || e <= ns) return 0;
		if(s <= ns && ne <= e) return arr[node].end() - upper_bound(arr[node].begin(),arr[node].end(),k);
		int mid = (ns+ne)/2;
		return greater(s,e,k,node*2,ns,mid)+greater(s,e,k,node*2+1,mid,ne);
	}
}st;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M,L = 0;
	cin >> N;
	for(int i=0; i < N; i++){
		int val; cin >> val;
		st.arr[MAX_ST/2+i].push_back(val);
	}
	st.construct();
	
	cin >> M;
	for(int i=0; i < M; i++){
		int s,e,k;
		cin >> s >> e >> k;
		L = st.greater((s^L)-1,e^L,k^L);
		cout << L << '\n';
	}

}

