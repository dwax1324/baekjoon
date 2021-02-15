// date: Fri Feb 12 10:18:58 2021
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

int N,M,K;
int check[10];
int pmt[10];
int mapp[51][51];
bool vis[51][51];
vector<tii>v;
int calc(int arr[51][51]);
void print(int copy_mapp[51][51]){
	cout << endl;
	for(int i=0; i < N; i++){
		for(int j=0; j < M; j++){
			cout << copy_mapp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int z_mapp[51][51];
void ignite(pii lu,int degr ,int degc , int copy_mapp[51][51]){
	int r = lu.o1, c = lu.o2;
	if(degr <= 1 || degc <= 1){
		return;
	}
	// right
	int nr = r, nc = c;
	for(nc = nc+1; nc <= c+degc; nc++){
		copy_mapp[nr][nc] = z_mapp[nr][nc-1];
	}
	// down
	nr =r, nc = c+degc;
	for(nr = nr+1; nr <= r+degr; nr++){
		copy_mapp[nr][nc] = z_mapp[nr-1][nc];
	}
	// left
	nr = r+degr, nc = c+degc;
	for(nc = nc-1; nc >= c; nc--){
		copy_mapp[nr][nc] = z_mapp[nr][nc+1];
	}
	// up
	nr = r + degr, nc = c;
	for(nr = nr-1; nr >= r; nr--){
		copy_mapp[nr][nc] =z_mapp[nr+1][nc];
	}
	// print(copy_mapp) ;
	copy_mapp[r][c] = z_mapp[r+1][c];
 	ignite({r+1,c+1}, degr-2,degc-2,copy_mapp);
}
int rotatee(vector<tii>&vv){
	int r,c,s;
	int copy_mapp[51][51];
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			copy_mapp[i][j] = mapp[i][j];
	
	for(int i=0; i < vv.size(); i++){
		for(int i=0; i < N; i++)
			for(int j=0; j < M; j++)
				z_mapp[i][j] = copy_mapp[i][j];
		tie(r,c,s) = vv[i];
		pii lu = {r-s,c-s};
		int degr = r+s - (r-s);
		int degc = c+s - (c-s);
		ignite(lu,degr,degc,copy_mapp);
	}
	return calc(copy_mapp);
}
int calc(int arr[51][51]){
	int ret = 1<<30;
	for(int i=0; i < N; i++){
	int tot=0;
		for(int j=0; j < M; j++){
			tot += arr[i][j];
		}
	ret = min(tot,ret);
	}
	return ret;
}



int perm(int a){
	if(a == K){
		vector<tii> temp;
		for(int i=0; i < K; i++){
			temp.push_back(v[pmt[i]]);
		}
		return rotatee(temp);
	}
	int ret=1<<30;
	for(int i=0; i< K; i++){
		if(!check[i]){
		check[i] = true;
		pmt[a] = i;
		ret = min(ret,perm(a+1));
		check[i] = false;
		}
	}
	return ret;	
}
int32_t main(){ this_is_main_function
	cin >> N >> M >> K;
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			cin >> mapp[i][j];

	for(int i=0; i < K ; i++){
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		v.push_back({a,b,c});
	}
	cout << perm(0);
}

