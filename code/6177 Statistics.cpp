// date: Wed Feb 24 18:50:38 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	vector<int> v(N);
	int SUM = 0;
	for(int i=0; i< N; i++){
		cin >> v[i];
		SUM += v[i];
	}
	sort(all(v));
	double ans1 = double(SUM)/double(v.size());
	double ans2;
	if(v.size() %2){
		ans2 = v[v.size()/2];
	}else{
		int t = v[v.size()/2], t2 = v[v.size()/2-1];
		ans2 = double(t+t2)/double(2);
	}
	cout << fixed << setprecision(9) << ans1 << '\n' << ans2;

}

