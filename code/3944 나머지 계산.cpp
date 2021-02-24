// date: Wed Feb 24 21:23:10 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int t; cin >> t; while(t--){
	int n; cin >> n;
	string s; cin >> s;
	int tot=0;
	for(auto x : s) tot += x-'0';
	cout << tot % (n-1) << '\n';
}
}
