// date: Thu Feb 25 16:44:13 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	bool ans=true;
	for(int i=1; i<= N; i++){
		int a; cin >> a;
		if(a%2 != i%2) ans=false;
	}
	cout << (ans ?"YES" : "NO");
}

