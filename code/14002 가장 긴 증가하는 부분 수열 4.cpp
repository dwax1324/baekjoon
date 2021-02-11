// date: Thu Feb 11 12:30:25 2021
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

int N;
vector<int> v;
int dp[1001];
int prevv[1001];
int last;
int lis(int curr){
	int&ret= dp[curr+1];
	if(ret!=-1)return ret;
	ret = 1;
	int bestnext = -1;
	for(int i = curr+1; i<N; i++){
		if(v[i] > v[curr] || curr == -1){
			int K = lis(i)+1;
			if(K > ret){
				ret = K;
				bestnext = i;
			}
		}
	}
	prevv[curr+1] = bestnext;
	return ret;
}
void reconstruct(int start, vector<int>& traces){
	if(start != -1) traces.push_back(v[start]);
	int nxt  = prevv[start+1];
	if(nxt != -1) reconstruct(nxt,traces);
}

int32_t main(){ this_is_main_function
	cin >> N;
	v.resize(N);
	for(int i=0; i < N; i++)
		cin >> v[i];
	memset(dp,-1,sizeof(dp));
	int ans = lis(-1)-1;
	cout << ans << endl;
	vector<int> traces;
	reconstruct(-1,traces);
	for(int i=0; i < traces.size(); i++)
		cout << traces[i] << ' ';
}

