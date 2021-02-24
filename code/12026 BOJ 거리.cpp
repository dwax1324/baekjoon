// date: Wed Feb 24 22:02:07 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int dp[1001][3];
string s; 
int n; 

char boj[4] ={'B','O','J'};
const int INF = 2e9;
int go(int idx, int prevv){
	if(idx == n-1) {
		return 0;
	}
	int &ret = dp[idx][prevv];
	if(ret != -1) return ret;
	ret=INF;
	for(int i=1; i < s.size(); i++){
		if(idx + i <= n-1 && s[idx+i] == boj[(prevv+1)%3]){
			ret = min(ret,go(idx+i,(prevv+1)%3) + i*i );
		}
	}
	return ret;
}

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n; cin >> s;
	memset(dp,-1,sizeof(dp));
	int ans = go(0,0);
	if(ans != INF) cout << ans;
	else cout << -1;
}

