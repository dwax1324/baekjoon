// date: Wed Feb 24 18:36:15 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M;
	cin >> N >> M;
	vector<string>v;
	map<string,int>order;
	for(int i=0;i < N; i++){
		string s;
		cin >> s;
		if(s.size() < M) continue;
		if(order[s])order[s]++;
		else{
			order[s] =1;
			v.push_back(s);
		}
	}
	sort(all(v),[&](string a, string b){
		if(order[a] == order[b]){
			if(a.size() == b.size()){
				return a<b;
			}else return a.size() > b.size();
		}
		return order[a] > order[b];
	});

	for(auto x : v) cout << x << '\n';

}

