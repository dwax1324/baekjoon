// #author <dwax1324>		#date <2021.03.24 12:08 UTC+9>
#include <bits/stdc++.h>
//#define int long long
using namespace std;using pii=pair<int,int>;using tii=tuple<int,int,int>;
#define all(x) (x).begin(), (x).end()


signed main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
#ifndef ONLINE_JUDGE
freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#endif
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

	int n; cin >> n;
	vector<int>v(n);
	for(auto& x :v) cin >> x;

	int ans =n;
	for(int i=1; i < n; i++){
		for(int j=0; j+i < n; j++){
			int SUM = 0;
			set<int>s;
			for(int k=j; k <= j+i; k++){
				SUM += v[k];
				s.insert(v[k]);
			}
			if(SUM%(i+1)==0 && s.count(SUM/(i+1))) {
				ans++;
			}
		}
	}
	cout << ans;
	

}
}
