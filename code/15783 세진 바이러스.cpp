// date: Thu Feb 18 00:12:19 2021
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

const int MAX= 100001;
int N,M;
vector<int> adj[MAX];

struct scc{
	int sn,id,sn_arr[MAX],id_arr[MAX],fin_arr[MAX];
	stack<int> stk;

	scc(){
		sn=id=0;
		for(int i=0; i < MAX; i++)
			sn_arr[i]=id_arr[i]=fin_arr[i]=0;
	}

	int dfs(int curr){
		int ret = id_arr[curr] = ++id;
		stk.push(curr);
		for(auto next : adj[curr]){
			if(id_arr[next] == 0) ret = min(ret,dfs(next));
			else if(fin_arr[next] == 0) ret = min(ret,id_arr[next]);
		}
		
		if( ret == id_arr[curr]){
			while(stk.size()){
				int t= stk.top(); stk.pop();
				sn_arr[t] = sn;
				fin_arr[t] = 1;
				if(t == curr) break;
			}
			sn++;
		}
		return ret;
	}

}scc;


int32_t main(){α
	cin >> N >> M;
	for(int i=0; i < M; i++){
		int a,b; cin >> a >> b;
		adj[a].push_back(b);
	}
	for(int i=0; i < N; i++){
		if(scc.id_arr[i] == 0 ) scc.dfs(i);
	}
	int inorder[MAX]={0};
	for(int i=0; i < N; i++){
		for(auto next : adj[i])
			if(scc.sn_arr[i] != scc.sn_arr[next]){
				inorder[scc.sn_arr[next]]++;
			}
	}
	int ans= 0;
	for(int i=0; i < scc.sn; i++) if(!inorder[i]) ans++;
	cout << ans;
}

