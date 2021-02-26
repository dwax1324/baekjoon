// date: Thu Feb 25 03:44:55 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int N; for(int tt=1 ; ; tt++){
cin >> N;
if(!N) break;
string s; cin >> s;

int ord[26];
int i=0;
for(auto x : s){
	ord[x-'A']= i++;
}
vector<string> v(N);
for(int i=0; i< N; i++)
	cin >> v[i];	

sort(all(v),[&](string a, string b){
	int L = min((int)a.size(),(int)b.size());
	for(int i=0; i< L; i++){
		if(a[i] == b[i]) continue;
		return ord[a[i]-'A'] < ord[b[i]-'A'];
	}
	return a.size() < b.size();
});

cout << "year " << tt << '\n';
for(auto x : v) cout << x << '\n';
}
}
