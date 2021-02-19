// date: Wed Feb 17 23:45:29 2021
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


const int MAX = 101;
int N;
int cost[MAX];
int adj[MAX][MAX];

struct scc{
	int id,sn,id_arr[MAX],sn_arr[MAX],fin_arr[MAX];
	vector<vector<int>> sccs;
	stack<int> stk;
	scc(){
		id=sn=0;
		for(int i=0; i < MAX; i++){
			id_arr[i] = sn_arr[i] = fin_arr[i] = 0;
		}
	}

	int dfs(int curr){
		int ret= id_arr[curr] = ++id;
		stk.push(curr);

		for(int i=0; i < MAX; i++){
			if(adj[curr][i] == 1){
				int next = i;
				if(id_arr[next] == 0) ret = min(ret, dfs(next));
				else if(fin_arr[next] == 0) ret = min(ret,id_arr[next]);
			}
		}

		if(ret == id_arr[curr]){
			vector<int> scc;
			while(stk.size()){
				int t = stk.top(); stk.pop();
				sn_arr[t] = sn;
				fin_arr[t] = true;	
				if(t == curr) break;
			}
			sn++;
			sccs.push_back(scc);
		}
		return ret;
	}

}scc;


int32_t main(){α
	cin >> N; for(int i=0; i < N; i++) cin >> cost[i];
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++){
			char a; cin >> a;
			adj[i][j] = (a=='1');
		}
	
	for(int i=0; i < N; i++){
		if(scc.id_arr[i] == 0) scc.dfs(i);
	}
	int ans[101];
	for(int i=0; i < N; i++) ans[i] = 1<<30;
	for(int i=0; i < N; i++){
		// cout << scc.sn_arr[i] << ' ';
		ans[scc.sn_arr[i]] = min(ans[scc.sn_arr[i]],cost[i]);
	}
	int rans=0;
	for(int i=0; i < scc.sn; i++) rans += ans[i];
	cout << rans;
}

