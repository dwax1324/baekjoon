// date: Tue Feb 23 22:19:47 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int N;
vector<int> v;
bool vis[100001];
int dp[100001];
int dfs(int curr){
	if(curr < 0 || curr >= N) return 0;	
	if(vis[curr]) return 0;
	vis[curr] = true;
	int &cnt = dp[curr];
	if(cnt != -1) return cnt;
	cnt =1;
	cnt += dfs(curr+v[curr]);
	cnt += dfs(curr-v[curr]);
	return cnt;
}
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N;
	for(int i=0; i < N; i++){
		int a; cin >> a;
		v.push_back(a);
	}
	memset(dp,-1,sizeof(dp));
	int s; cin >> s;
	s--;
	cout << dfs(s);

}

