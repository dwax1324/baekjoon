// date: Wed Feb 24 04:13:55 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int n;
	while(1){
		cin >> n;
		if(!n) break;
		vector<int>v(n);
		for(int i=0; i < n; i++){
			cin >> v[i];
		}
		sort(all(v),[](int a, int b){
			return a <b;
		});
		int t= *upper_bound(all(v),0);
		sort(all(v),[&](int a, int b){
			if(a == 0 && b ==t) return b <a;
			if(b == 0 && a ==t) return a <b;
			return a > b;
		});
		int sz = v.size();
		if(v[sz-1] == 0) swap(v[sz-1],v[sz-2]);
		if(n%2==0 && v[sz-2] == 0) swap(v[sz-2],v[sz-3]);
//		cout << t << '\n';
//		for(auto x : v) cout << x << ' ' ;
//		cout << '\n';
		int off=1;
		int ans=0;
		for(int i=0; i< n; i++){
			if(i!=0 && i%2==0) off*=10;
			ans += v[i] * off;
		}
		cout << ans << '\n';
	}

}

