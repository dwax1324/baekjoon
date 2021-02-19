// date: Fri Feb 19 23:06:01 2021
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

int32_t main(){α
	int N; cin >> N;
	int dist[51][51];
	const int INF = 1e9;
	for(int i=0; i < N; i++)
		for(int j=0;j <N; j++){
			char a; cin >> a;
			if(i==j) dist[i][j] = 0;
			else dist[i][j] = a=='Y' ? 1 : INF;
		}
	
	
	for(int k=0; k < N; k++)
		for(int i=0; i < N; i++)
			for(int j=0; j < N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int ans =0;
	for(int i=0; i < N; i++){
		int cnt=0;
		for(int j=0; j < N; j++){
			//cout << dist[i][j] << ' ';
			if(dist[i][j] && dist[i][j] <= 2) cnt++;
		}
		ans = max(ans,cnt);
	}
	cout << ans;


}

