// date: Fri Feb 19 13:25:11 2021
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

const int MAXN= 1001, MAXV = 2*MAXN;
int N,M,K;
vector<int> adj[MAXV];

struct bm{
	int A[MAXV],B[MAXV],vis[MAXV];
	void init(){
		for(int i=0; i < MAXV; i++)
			A[i] = B[i] = -1;
	}
	bm(){
		init();
	}
	void rsvis(){
		memset(vis,0,sizeof(vis));
	}

	function<bool(int)> dfs= [&](int a){
		vis[a] = true;
		for(auto &b: adj[a]){
			if(B[b] == -1 || (vis[B[b]]==0 && dfs(B[b]))){
				A[a] =b;
				B[b] =a;
				return true;
			}
		}
		return false;

	};
}bm;


int32_t main(){α
	cin >> N>> M >> K;
	for(int i=0; i <N; i++){
		int t; cin >> t; while(t--){
			int a; cin >> a; a--;
			adj[i].push_back(a);
			adj[i+MAXN].push_back(a);
		}
	}
	int ans=0;
	for(int i=0; i < N; i++){
		bm.rsvis();
		if(bm.A[i]==-1){
			ans += bm.dfs(i);
		}
	}
	int cnt=0;
	for(int i=MAXN; i < MAXN+N; i++){
		bm.rsvis();
		if(bm.A[i] ==-1){
			if(bm.dfs(i)){
				ans++;
				if(++cnt == K) break;
			}
		}
	}
	cout << ans;
}


