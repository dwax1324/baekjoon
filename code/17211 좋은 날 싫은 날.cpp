// date: Fri Feb 12 00:18:52 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define this_is_main_function ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
// #define int int64_t


int N, C;
vector<double>v;
// goodays
double dp[101][2];
double go(int d, int c){
	if( d== N) {
		if(c == 0)
			return 1.0;
		return 0;
	}
	double &ret = dp[d][c];
	if(ret > -0.5) return ret;
	ret =0;
	if(c == 0) ret += go(d+1, 0) * v[0] + go(d+1,1) * v[1];
	else ret +=  go(d+1,0) *v[2] + go(d+1,1)*v[3];
	return ret;
}
double go2(int d, int c){
	if( d== N) {
		if(c == 1)
			return 1.0;
		return 0;
	}
	double&ret = dp[d][c];
	if(ret > -0.5) return ret;
	ret=0;
	if(c == 0) ret += go2(d+1, 0) * v[0] + go2(d+1,1) * v[1];
	else ret +=  go2(d+1,0) *v[2] + go2(d+1,1)*v[3];
	return ret;
}



int32_t main(){ this_is_main_function
	cin >> N>> C;
	v.resize(4);
	for(int i=0; i <4 ;i++) cin >> v[i];
	for(int i=0; i < 101; i++)
		for(int j=0; j <2; j++)
			dp[i][j] = -1.0;
	cout <<  (int)(go(0,C)*1000.0)  << endl;
	for(int i=0; i < 101; i++)
		for(int j=0;j <2; j++)
			dp[i][j] = -1.0;
	cout << (int)(go2(0,C)*1000.0);
}

