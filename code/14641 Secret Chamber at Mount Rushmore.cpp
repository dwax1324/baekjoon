// date: Tue Feb 16 02:59:51 2021
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

int N,Q;
int dist[26][26];
const int INF = 1e9;
int32_t main(){ this_is_main_function
	cin >> N>> Q;
	for(int i=0; i < 26; i++)
		for(int j=0; j < 26 ;j++)
			dist[i][j] =  (i==j ?0 : INF);
	
	for(int i=0; i < N; i++){
		char u,v; cin >> u >> v;
		dist[u-'a'][v-'a'] = 1;
	}
	for(int k=0; k < 26; k++)
		for(int i=0; i < 26; i++)
			for(int j=0; j < 26; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	for(int i=0; i < Q; i++){
		string a,b; cin >> a >> b;
		if(a.size() != b.size()) {cout << "no" << endl; continue;}
		int ok=true;
		for(int i=0; i < a.size(); i++){
			if(dist[a[i]-'a'][b[i]-'a'] ==INF) ok=false;
		}
		cout << ( ok ? "yes" : "no" ) << endl;
	}
			


}

