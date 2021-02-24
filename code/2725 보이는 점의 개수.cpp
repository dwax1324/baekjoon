// date: Wed Feb 24 16:18:54 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int dp[1001];
dp[1] = 3;
function<int(int,int)> gcd= [&](int a, int b){
	return b ? gcd(b,a%b) : a;
};
for(int i=2; i < 1001; i++){
	int cnt=0;
	// x-axis
	for(int j=1; j < i ; j++){
		if(gcd(i,j) ==1) cnt++;	
	}
	// y-axis
	for(int j=1; j < i ; j++){
		if(gcd(i,j) ==1) cnt++;	
	}
	// ...or just cnt*2
	dp[i] = dp[i-1] + cnt;
}
int T; cin >> T; while(T--){
 int a; cin >> a; cout << dp[a] << '\n';	
}
}

