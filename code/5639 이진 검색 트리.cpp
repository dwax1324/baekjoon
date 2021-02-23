// date: Tue Feb 23 13:40:49 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;



vector<int> v;
void go(int start, int end){
	if(start >= end) return;
	int upperIdx = distance(v.begin(),upper_bound(v.begin()+start+1,v.begin()+end,v[start]));

	go(start+1,upperIdx);
	go(upperIdx,end);
	cout << v[start] << '\n';
}

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	
	int a;
	while(cin >> a){
		v.push_back(a);
	}
	go(0,v.size());
}

