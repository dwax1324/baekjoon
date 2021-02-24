// date: Wed Feb 24 17:28:00 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int t=1;
int n; 
while(1){
	cin >> n;
	if(n==0)break;
	cout << t++ << '\n';
	vector<string> v(n);
	cin.ignore();
	for(int i=0;i < n; i++){
		getline(cin,v[i]);
	}sort(all(v)); 
	for(auto x : v) cout << x << '\n';
}
}

