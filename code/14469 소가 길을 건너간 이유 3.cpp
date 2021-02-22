// date: Mon Feb 22 23:36:35 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	vector<pii> v;
	for(int i=0; i < N; i++){
		int s,t; cin >> s >> t;
		v.push_back({s,t});
	}
	sort(all(v));
	int start=0;
	int prevv=0;
	for(int i=0; i < v.size(); i++){
		start = max(prevv,v[i].first);	
		prevv = start + v[i].second;
	}
	cout <<prevv;
}

