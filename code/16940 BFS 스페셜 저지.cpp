// date: Wed Feb 17 15:41:23 2021
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
vector<int> adj[100001];
int order[100001];
int order_cmp[100001];
int vis[100001];
vector<int> each_lev;
int32_t main(){ this_is_main_function
	cin >> N;
	for(int i=0; i < N-1; i++){
		int a,b; cin >> a >> b;
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0; i < N; i++){
		cin >> order[i];
		order[i]--;
	}
	
	if(order[0] != 0) {cout << 0; exit(0);}
	queue<int> q;
	q.push(0);
	vis[0] = true;
	int idx=1;
	while(q.size()){
        set<int> s;
		int curr = q.front(); q.pop();
		int sz = 0;
		for(auto next : adj[curr]){
			if(!vis[next]){
				s.insert(next);
				vis[next] =true;
				sz++;
			}
		}
		for(int i= idx; i < idx+sz; i++){
			if(s.count(order[i]) == 0) {cout << 0; return 0;}
			else q.push(order[i]);
		}
		idx = idx + sz;
	}
	cout << 1;

}

