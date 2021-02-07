// Sun Feb  7 09:09:01 KST 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
// #define int int64_t

// one component -> two component
// n <= 10, must be brutal force
// cutting out every edges
// 4 3, 4 1, 12, 32, 26, 25
// ...and count evey compents if it is only two, max(ans,cnt)

// No! edges maximum is = 100
// so need to divide by nodes

int n;
bool edges[11][11];
int people[11];
int vis[11];
bool copy_edges[11][11];
int cnt_dfs(int curr){
	vis[curr]= true;
	int ret = people[curr]; 
	for(int i=0; i < n; i++){
		if(copy_edges[curr][i] ==1 && vis[i] == 0){
			ret += cnt_dfs(i);
		}
	}
	return ret;
}


int divide(vector<int>& picked){
	memset(vis,0,sizeof(vis));
	for(int i=0; i< n; i++)
		for(int j=0; j < n; j++)
			copy_edges[i][j] = edges[i][j];

	// remove all the picked node's edges
	for(auto y : picked){
		memset(copy_edges[y],0,sizeof(copy_edges[y]));
		// but add the edges if there were already connected and in the same component
		for(int i=0; i < n; i++){
			if(i ==y ) continue;
			if(edges[y][i] != 0 && find(all(picked),i) != picked.end()){
				copy_edges[y][i] =1;
			}
		}
	}
	// count components
	vector<int>zz;
	for(int i=0; i < n; i++){
		if(!vis[i])
			zz.push_back(cnt_dfs(i));
	}
	if(sz(zz) !=2) return 1<<30;
	return abs(zz[0]-zz[1]);

}

// combination
int dfs(int choose, int to_choose,vector<int> &picked){
	if(choose == to_choose){
		// cout << divide(picked) << ' ';
		return divide(picked);
	}
	int first = picked.size()?picked.back()+1 : 0;
	int ret= 1<<30;
	for(int i=first ;i < n; i++){
		picked.push_back(i);
		ret = min(ret,dfs(choose+1,to_choose,picked));
		picked.pop_back();
	}
	return ret;
}

void solve(){
	cin >> n;
	for(int i=0; i < n; i++) cin >> people[i];
	for(int i=0;  i< n; i++){
		int a; cin >> a;
		for(int j=0; j < a; j++){
			int b; cin >> b; b--;
			edges[i][b] =1;
			edges[b][i] =1;
		}
	}
	// select 1~n/2 nodes as one component
	vector<int> t;
	int ans =1<<30;
	for(int i=1; i<= n; i++){
		ans = min(ans,dfs(0,i,t));
	}
	if (ans == 1<<30 ) cout << -1;
	else cout << ans;
}


int32_t main(){ F int t=1;
// cin >> t;
while(t--) solve();}

