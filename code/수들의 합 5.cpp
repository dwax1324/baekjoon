// date: Mon Feb 22 20:51:11 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	
	int cnt=0;

	for(int j=1; j< N; j++){
		int start = j*(j+1)/2;
		if(N-start<0)break;
		if((N-start)%j==0)cnt++;
	}
	cout << cnt;

}

