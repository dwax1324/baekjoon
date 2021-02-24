// date: Wed Feb 24 13:51:59 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	vector<int> v(N);
	for(int i=0; i< N; i++){
		cin >> v[i];
	}
	sort(all(v));
	int l= 0, r = v.size()-1;

	int prevv= 1e11;
	int mid;
	int ret;
	while(l < r ){
		mid = (l+r)/2;
		int temp = 0;
		int piv = v[mid];
		for(auto x: v) temp += abs(piv - x);
		if(temp <= prevv){
			r = mid-1;
			ret = piv;
			prevv= temp;
		}else{
			l = mid+1;
		}
		// cout << v[mid] << ' ' << temp << '\n';
	}
	cout << ret;

}

