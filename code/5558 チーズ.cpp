// 2021-02-09
// bfs
#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
int N, M,C;
char mapp[1001][1001];
bool vis[1001][1001];
vector<pii> coords;
int bfs(int a){
	memset(vis,0,sizeof(vis));
	queue<pii> q;
	q.push(coords[a]);
	vis[coords[a].first][coords[a].second] = true;
	int ret;
	for(ret=0;q.size();ret++){
		int qs = q.size();
		for(int i=0; i < qs; i++){
			int r= q.front().first, c = q.front().second; q.pop();
			if(r== coords[a+1].first && c == coords[a+1].second){
				return ret;
			}
			for(int d=0;d < 4; d++){
				int nr = r + "2011"[d]-'1';
				int nc = c + "1102"[d]-'1';
				if(nr <0 || nc <0 || nr >= N || nc >= M) continue;
				if(mapp[nr][nc] == 'X' || vis[nr][nc]) continue;
				q.push({nr,nc});
				vis[nr][nc]=true;
		}
	}
	}
	return -1;
}


int main(){
	cin >> N >> M >> C;
	int sr,sc;
	coords.resize(C+1);
	for(int i=0; i < N ; i++){
		for(int j=0; j < M; j++){
			cin >> mapp[i][j];
			if(mapp[i][j] == 'S'){
				sr = i; sc = j;
				coords[0] = {sr,sc};
			}
			else if(mapp[i][j] <= '9' && mapp[i][j] >='0'){
				coords[mapp[i][j]-'0'] = {i,j};
			}
		}
	}
	int ans =0;
	for(int i=0; i < C ; i++){
		ans += bfs(i);
	}
	cout << ans;
}
