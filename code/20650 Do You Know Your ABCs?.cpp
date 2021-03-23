// #author <dwax1324>		#date <2021.03.24 02:31 UTC+9>
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
	vector<int>v(7);
	for(auto &it : v) cin >> it;
	sort(all(v));
	cout << v[0] << ' ' << v[1] << ' ' << v[v.size()-1]-v[0]-v[1];

}
}
