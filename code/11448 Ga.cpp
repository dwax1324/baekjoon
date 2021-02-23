// date: Tue Feb 23 03:25:04 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int t; cin >> t; while(t--){
	int N;
	cin >> N;
	int mapp[101][101];
	int vis[101][101]={0};
	queue<pii> q;
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++){
			char a; cin >> a;
			mapp[i][j] = (a=='b' || a=='w');
			if(a == 'w'){
				q.push({i,j});
				vis[i][j] = true;
			}
		}
	int cnt=0;
	while(q.size()){
		int r = q.front().first, c = q.front().second; q.pop();
		for(int d=0; d< 8; d++){
			int nr = r + "20112200"[d]-'1';
			int nc = c + "11022020"[d]-'1';
			if(nr <0 || nc <0 || nr >= N || nc >= N) continue;
			if(mapp[nr][nc] || vis[nr][nc]) continue;
			cnt++;
			q.push({nr,nc});
			vis[nr][nc] = true;
		}
	}
	cout << cnt << '\n';


}
}

