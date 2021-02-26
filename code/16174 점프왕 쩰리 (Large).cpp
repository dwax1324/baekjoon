// date: Thu Feb 25 22:50:55 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	int mapp[65][65];
	for(int i=0; i < N; i++)
		for(int j=0; j< N ;j++)
			cin >> mapp[i][j];

	int dp[65][65];
	memset(dp,-1,sizeof(dp));
	function<int(int,int)> go = [&](int r, int c){
		if(r <0 || c <0 || r >= N || c >= N) return 0;
		if(r == N-1 && c == N-1) return 1;
		int &ret = dp[r][c];
		if(ret != -1) return ret;
		ret =0;
		int jump = mapp[r][c];
		ret |= go(r+jump,c);
		ret |= go(r,c+jump);
		return ret;
	};


	if(go(0,0)) cout << "HaruHaru";
	else cout << "Hing";

}


