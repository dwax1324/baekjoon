// date: Wed Feb 24 14:29:14 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;



int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int M; cin >> M;
	vector<int> v(M);
	double ans=0;
	int tot =0;
	for(int i=0; i < M; i++){
		cin >> v[i];
		tot += v[i];
	}

	int k; cin >> k;
	for(auto x : v){
		double temp =1;
		for(int j=0; j< k; j++){
			temp *= double(x-j)/double(tot-j);	
		}
		ans += temp;
	}
	cout << fixed << setprecision(9) << ans;

