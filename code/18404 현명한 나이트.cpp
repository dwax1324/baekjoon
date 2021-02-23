// date: Tue Feb 23 20:07:31 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int dxy[8][2] = {
	{-1,-2},
	{-2,-1},
	{-2,1},
	{-1,2},
	{1,2},
	{2,1},
	{2,-1},
	{1,-2}
};
int arr[505][505];
struct info{
	int cnt,ans;
	bool operator<(const info&a)const {
		return cnt < a.cnt;
	}
};
map<pii,info> pos;
int N,M;
void print(){
	cout << '\n';
	for(int i=1; i <= N; i++){
		for(int j=1; j<= N; j++){
			cout << arr[i][j];
		}
		cout << '\n';
	}
}
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N>> M;	
	int X,Y; cin >> X >>Y;
	int cnt=1;
	for(int i=0; i< M; i++){
		int a,b; cin >> a >> b;
		arr[a][b] =1;
		pos[{a,b}] = {cnt++,0};
	}

	queue<pii> q;
	int vis[505][505] = {0};
	vis[X][Y] =1;
	q.push({X,Y});
	int lev=0;
	for(int lev=1;q.size(); lev++){
		int qs = q.size();
		for(int i=0; i< qs; i++){
			int r = q.front().first, c = q.front().second; q.pop();
			for(int d=0; d<8; d++){
				int nr = r + dxy[d][0];
				int nc = c + dxy[d][1];
				if(nr < 1 || nc < 1 || nr >= N+1 || nc >= N+1) continue;
				if(vis[nr][nc]) continue;
				if(arr[nr][nc] ==1){
					pos[{nr,nc}].ans = lev;
				}
				vis[nr][nc] = true;
				q.push({nr,nc});
			}
		}
	}
	vector<int> ans(250005);
	for(auto x : pos){
		ans[x.second.cnt] = x.second.ans;	
	}
	for(int i=1; i<= M; i++){
		cout << ans[i] << ' ';
	}
}

