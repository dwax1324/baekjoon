// date: Wed Feb 24 23:29:38 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int MOD = 1e9+9;
int dp[100001][2];
int N,M;
int go(int summ, int T){
	int &ret = dp[summ][T];
	if(ret!= -1)return ret;
	if(summ == 0) return ret = !T;
	ret =0;

	for(int i=1 ; i<=3; i++){
		if(summ-i >=0) ret = (ret + go(summ-i, !T)) %MOD;
	}
	return ret;
}
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
memset(dp,-1,sizeof(dp));
int T; cin >> T; while(T--){
	cin >> N;
	cout << go(N,1) << ' ' <<  go(N,0) << '\n';
}
}

