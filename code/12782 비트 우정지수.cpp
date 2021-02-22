// date: Tue Feb 23 01:56:51 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int t; cin >> t; while(t--){
	string a, b;
	cin >> a >> b;
	int cnt1=0,cnt2=0;
	for(int i=0; i < a.size(); i++){
		if(a[i] == '0' && b[i] == '1') cnt1++;
		if(a[i] == '1' && b[i] == '0') cnt2++;
	}
	cout << max(cnt1,cnt2) << '\n';
}
}

