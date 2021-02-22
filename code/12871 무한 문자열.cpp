// date: Tue Feb 23 02:02:34 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	string a,b;
	cin >> a >> b;
	string ta="",tb="";
	for(int i=0; i <10000; i++){
		ta += a; tb += b;	
	}
	
	bool ok=true;
	for(int i=0; i < 10000; i++){
		if(ta[i]!=tb[i]) ok = false;	
	}
	cout << ok;

}

