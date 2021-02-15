// date: Mon Feb 15 01:11:45 2021
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

int N, M;
vector<int> adj[1001];
int order[1001];
int32_t main(){ this_is_main_function
	cin >> N >> M;	
	for(int i=0; i < M; i++){
		int a,b; cin >> a >> b; a--;b--;
		adj[a].push_back(b);
		order[b]++;
	}
	queue<int> q;
	for(int i=0; i < N; i++){
		if(order[i] == 0 ) q.push(i);	
	}

	int res[1001]={0};
	for(int level=0;q.size();level++){
		int qs = q.size();
		for(int i=0; i < qs ; i++){
			int curr = q.front(); q.pop();
			res[curr] = level;	
			for(auto next : adj[curr]){
				order[next]--;
				if(order[next] == 0) q.push(next);
			}
		}
	}
	for(int i=0; i < N; i++){
		cout << res[i] + 1 << ' ' ;
	}
}

