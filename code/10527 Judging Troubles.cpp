// date: Wed Feb 24 18:59:38 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	map<string,pii> mp;
	for(int i=0; i< N; i++){
		string s; cin >> s;
		if(mp[s].first) mp[s].first++;
		else mp[s].first = 1;
	}

	for(int i=0; i< N; i++){
		string s; cin >> s;
		if(mp[s].second) mp[s].second++;
		else mp[s].second = 1;
	}
	int ans=0;
	for(auto x : mp){
		ans += min(x.second.second,x.second.first);
	}
	cout << ans;
}

