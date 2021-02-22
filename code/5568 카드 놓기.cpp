// date: Mon Feb 22 22:57:33 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int N,K;

vector<string> v;
set<string> t;
void go(int k, string s){
	if(k==K){
		string temp="";
		for(int i=0; i <K; i++){
			temp += v[i];
		}
		t.insert(temp);
		return;
	}
	
	for(int i=k; i < N; i++){
		swap(v[k],v[i]);
		go(k+1,s);
		swap(v[k],v[i]);
	}

}

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N >> K;
	for(int i=0; i < N; i++){
		string s; cin >> s;
		v.push_back(s);
	}
	
	go(0,"");
	// for(auto x : t) cout << x << ' ';
	cout << t.size();
}

