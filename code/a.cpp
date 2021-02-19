// date: Fri Feb 19 00:35:51 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define α ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
// #define int int64_t
const int MAXN = 1001*2;
int N,M;
vector<int> adj[MAXN];

int A[MAXN],B[MAXN],vis[MAXN];
struct bma{

	static bool dfs(int a){
		vis[a] = true;
		for(auto b : adj[a]){
			if(B[b] == -1 || (vis[B[b]] == 0 &&  dfs(B[b]))){
				A[a] = b;
				B[b] = a;
				return true;
			}
		}
		return false;
	}

}bm;


int32_t main(){α
	cin >> N>> M;
	memset(A,-1,sizeof(A));
	memset(B,-1,sizeof(B));
	for(int i=0; i < N; i++){
		int a; cin >> a; while(a--){
			int t; cin >> t; t--;
			adj[i*2].push_back(t);	
			adj[i*2+1].push_back(t);
		}
	}
	int ans=0;
	for(int i=0; i < N*2; i++){
		if(A[i] == -1){
			memset(vis,0,sizeof(vis));
			if(bm.dfs(i)) ans++;
		}
	}
	cout << ans;
}



