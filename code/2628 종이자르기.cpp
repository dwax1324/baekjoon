// date: Mon Feb 22 19:59:47 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int arr[201][201];
bool vis[201][201];

int M,N,Q;
int bfs(int y, int x){
	int ret =0;
	queue<pii> q;
	vis[y][x]= true;
	q.push({y,x});
	while(q.size()){
		int r = q.front().first, c = q.front().second; q.pop();
		if(r%2 && c%2) ret++;
		for(int d=0; d<4; d++){
			int nr = r+"2011"[d]-'1';
			int nc = c+"1102"[d]-'1';
			if(nr <1 || nc <1 || nr >= N*2+1 || nc >=M*2+1) continue;
			if(arr[nr][nc] == 1 || vis[nr][nc]) continue;
			vis[nr][nc] = true;
			q.push({nr,nc});
		}
	}
	return ret;
}
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> M>> N >> Q;
	
	for(int i=0; i <Q; i++){
		int a,b;
		cin >> a >> b;
		if(a==0){
			for(int j=1; j <=M*2; j++)
				arr[b*2][j] =1;
		}else{
			for(int j=1; j<=N*2; j++)
				arr[j][b*2] = 1;
		}
	}
//	for(int i=1; i<= N*2; i++){
//		for(int j=1; j<= M*2; j++){
//			cout << arr[i][j] << ' ';
//		}
//		cout << '\n';
//	}
	
	int ans=0;
	for(int i=1; i<=2*N; i++){
		for(int j=1;j<=2*M;j++){
			if(!vis[i][j] && arr[i][j] != 1){
				ans = max(ans,bfs(i,j));
			}
		}
	}
	cout << ans;

}

