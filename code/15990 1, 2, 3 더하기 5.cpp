// date: Wed Feb 24 20:36:09 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int dp[4][100001];
int n; 
const int mod = 1e9+9;
int go(int prevv, int summ){
	if(summ == 0){
		return 1;		
	}
	int &ret = dp[prevv][summ];
	if(ret!=-1) return ret;
	ret = 0;
	for(int i=1; i < 4 ; i++){
		if(i != prevv && summ-i >= 0) {
			ret += go(i,summ-i);
			ret %= mod;
		}
	}
	return ret;
}

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
memset(dp,-1,sizeof(dp));
go(0,100000);
int T; cin >> T; while(T--){
	cin >> n;
	cout << go(0,n)%mod << '\n';
}
}
