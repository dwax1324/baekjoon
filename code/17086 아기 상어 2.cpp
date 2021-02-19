// date: Sat Feb 20 04:59:50 2021
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

int main(){
	int N,M; cin >> N>> M;
	int mapp[51][51];
	int vis[51][51]={0};
	queue<pii>q;
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
		{
			cin >> mapp[i][j];
			if(mapp[i][j]){
				q.push({i,j});
				vis[i][j]=true;
			}
		}
	int ret;	
	for(ret=0;q.size();ret++){
		int qs = q.size();
		for(int i=0; i < qs; i++){
			int r = q.front().o1 , c = q.front().o2; q.pop();
			for(int d= 0; d <8 ; d++){
				int nr = r + "20112200"[d]-'1';
				int nc = c + "11022020"[d]-'1';
				if(nr <0 || nc <0 || nr >= N || nc >=M) continue;
				if(mapp[nr][nc] || vis[nr][nc]) continue;
				vis[nr][nc] = true;
				q.push({nr,nc});
			}
		}
	}
	cout << ret-1;

}
