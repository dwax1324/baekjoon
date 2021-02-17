// date: Tue Feb 16 04:28:49 2021
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
const int MAX =100001;
int N,M,Q;
int indegree[MAX];
vector<int> adj[MAX];
int res[MAX];
int32_t main(){ this_is_main_function
	cin >> N >> M >> Q;
	for(int i=0; i < M; i++){
		int a,b; cin >> a >> b; a--;b--;
		indegree[b]++;
		adj[a].push_back(b);
	}
	queue<int> q;
	for(int i=0; i < N; i++){
		if(indegree[i] == 0) q.push(i);
	}
	for(int i=0; i < N ;i++){
		int curr =q.front(); q.pop();
		res[curr] = i;	
		for(auto next : adj[curr]){
			indegree[next]--;
			if(indegree[next]==0) q.push(next);
		}
	}
	int ok = true;
	int arr[MAX]={0};
	for(int i=0; i <Q; i++){
		int a,b; cin >> a >> b; b--;
		if(a==1){
			if(res[b]==0) arr[res[b]]++;
			else{
				if(arr[res[b-1]]) arr[res[b]]++;
				else ok=false;
			}
		}else{
			arr[res[b]]--;
			if(arr[res[b]] <0) ok = false;
		}
	}
	if(ok) cout << "King-God-Emperor";
	else cout << "Lier!";

}

