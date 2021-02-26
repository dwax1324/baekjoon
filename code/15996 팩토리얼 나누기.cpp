// date: Thu Feb 25 15:14:43 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,A; cin >> N >> A;
	int cnt=0;

	int Z =	N/A;
	int ans = Z;
	int ra = A;
	for(int i=0;Z;i++){
		//cout << ans <<  ' ' << Z << endl;
		Z/=ra;
		ans += Z;
		A*=A;
	}
	cout << ans;

}

