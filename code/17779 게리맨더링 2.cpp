// Wed Feb 10 13:27:52 KST 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
// #define int int64_t
/*
	주어진대로 구현하다가
	일일히 맵에 찍어볼 필요가 없다는걸 느끼고 크게 좌절
	
	식이 주어져서 친절한 문제구나..라는 생각이 듬
	5번구역을 구하는데 식만 세워보면 될텐데
	펜잡기싫어서 bfs돌림

*/

// make combinations 20 * 20 for d1,d2 1..20
// for each cell run 400 possible d1,d2 => 400 * 400
// checking + copying + marking => total roghly 400^3 27000000
int N;
int mapp[21][21];
vector<pii> dist;
const int INF = 1<<30;


bool possible_distance(int x, int y, pii a){
	int d1 = a.o1 , d2 = a.o2;
	if(x + d1 + d2 > N) return false;
	if(y - d1 < 1 || y + d2> N) return false;
	return true;
}
void draw(int arr[21][21], int x ,int y, pii a){
	int d1 = a.o1, d2 = a.o2;
	int t=0,nx = x, ny = y;
	bool vis[21][21];
	memset(vis,0,sizeof(vis));
	while(1){
		arr[nx][ny] =1;		
		nx+=1; ny-=1;
		if(t++ == d1) break;
	}
	t =0; nx =x; ny =y;
	while(1){
		arr[nx][ny] =1;	
		nx++;ny++;
		if(t++ == d2) break;
	}
	t =0; nx= x +d1; ny = y-d1;
	while(1){
		arr[nx][ny] =1;
		nx++;ny++;
		if(t++ == d2) break;
	}
	t=0;nx=x+d2;ny=y+d2;
	while(1){
		arr[nx][ny] = 1;
		nx++;ny--;
		if(t++ == d1) break;
	} 
	queue<pii> q;
	q.push({1,1});
	q.push({1,N});
	q.push({N,1});
	q.push({N,N});
	vis[1][1] = true;
	vis[1][N] = true;
	vis[N][1] = true;
	vis[N][N] = true;
	while(q.size()){
		int cr = q.front().o1, cc = q.front().o2;
		arr[cr][cc] =2;
		q.pop();
		for(int d=0; d< 4 ;d++){
			int nr = cr + "2011"[d]-'1';
			int nc = cc + "1102"[d]-'1';
			if(vis[nr][nc]) continue;
			if(nr <1 || nc < 1 || nr > N || nc > N) continue;
			if(arr[nr][nc] == 1) continue;
			vis[nr][nc] = 1;
			q.push({nr,nc});
		}

	}
}


int calc_mnmx(int x, int y, pii a){
	int copy_mapp[21][21];
	memset(copy_mapp,0,sizeof(copy_mapp));	
	draw(copy_mapp,x,y,a);
	int d1 = a.o1, d2 = a.o2;	
	int sums[5]={0};
	for(int r=1; r <= N; r++)
		for(int c =1 ;c <= N; c++){
			// inside of boundary 5
			if(copy_mapp[r][c] == 1 || copy_mapp[r][c] == 0){
				sums[4] += mapp[r][c];
			}
			// 1
			else if(1 <= r && r < x+d1 && 1 <= c && c <= y){
				sums[0] += mapp[r][c];
			//2
			}else if(1 <= r && r <= x+d2 && y < c && c <= N){
				sums[1] += mapp[r][c];	
			//3
			}else if(x+d1 <= r && r <= N && 1<= c && c < y-d1+d2){
				sums[2] += mapp[r][c];
			//4
			}else if(x+d2 < r && r <= N && y-d1+d2 <= c && c <= N){
				sums[3] += mapp[r][c];
			}
		}

	for(int i=0; i < 5; i++){
		// cout << sums[i] << ' ';
	}
	return *max_element(sums,sums+5) - *min_element(sums,sums+5);

}


void solve(){
	cin >> N;
	for(int i=1; i <= N; i++)
		for(int j=1; j <= N; j++)
			cin >> mapp[i][j];
		
	for(int i=1; i < N+1; i++)
		for(int j=1; j< N+1; j++)
			dist.push_back({i,j});
	int ans=INF;	
	for(int i=0; i < dist.size(); i++){
		for(int x= 1; x <= N; x++){
			for(int y =1; y <= N; y++){
				if(!possible_distance(x,y,dist[i])) continue;
				ans = min(ans,calc_mnmx(x,y,dist[i]));
			}
		}
	}
	cout << ans;
}


int32_t main(){ F int t=1;
// cin >> t;
while(t--) solve();}

