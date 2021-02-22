// date: Tue Feb 23 01:29:52 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	vector<pii> v;
	for(int i=0; i < N; i++){
		int a,b;
		cin >> a >> b;	
		v.push_back({a,b});
	}
	sort(all(v),[](pii a, pii b){
		if(a.first == b.first) return a.second > b.second;
		return a.first > b.first;
	});
	int cnt=0;	
	for(int i=0; i < N; i++){
		bool ok= true;
		int curr = v[i].second;
		for(int j=i+1; j < N; j++){
			if(v[j].second <= curr) ok = false;
		}
		if(ok) cnt++;
	}
	cout << cnt;

}

