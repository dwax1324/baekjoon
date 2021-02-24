// date: Wed Feb 24 22:25:44 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int dp[182][32769][4];

int n; 
int go(int x, int summ, int cnt){
	if(summ == 0){
		// cout << cnt << ' ';
		return 1;
	}
	if(x == 182 || cnt == 4) return 0;
	int &ret = dp[x][summ][cnt];
	if(ret!= -1)return ret;
	ret = go(x+1,summ,cnt);
	if( summ >= x*x){
		ret += go(x,summ-(x*x),cnt+1);
	}
	return ret;

}

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
memset(dp,-1,sizeof(dp));
while(1){
	cin >> n;
	if(n == 0) break;
	cout << go(1,n,0) << '\n';
}
}
