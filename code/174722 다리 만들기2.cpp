// date: Tue Feb 16 11:04:52 2021
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


int N,M;
int mapp[11][11];
int num[11][11];
struct disj{
	int sz[101],pa[101];
	void init(int N, int M){
		for(int i=0; i <= N*M; i++){
			sz[i] = 1;
			pa[i] = i;
		}
	}
	int find(int curr){ return pa[curr] = (pa[curr] == curr?curr: find(pa[curr]));}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return false;
		pa[q] = p;
		sz[p] += sz[q];
		return true;
	}

}disj;


vector<int> all_ones;	
bool all_same(){
	int p = all_ones[0];
	p = disj.find(p);
	for(int i=1; i< all_ones.size(); i++){
		if(disj.find(all_ones[i]) != p) return false;
	}
	return true;
}

struct ifo{
	int len,sr,sc,er,ec;
	bool operator<(const ifo &a) const{
		return len > a.len;
	}
};

int add_edge(){
	priority_queue<ifo> cands;
	for(int i=0; i < N; i++){
		for(int j=0; j < M; j++){
			if(mapp[i][j] == 1){
				ifo info;
				info.sr = i; info.sc = j;
				for(int d=0; d< 4; d++){
					int di = "2011"[d]-'1', dj = "1102"[d]-'1';
					int ni = i + di;
					int nj = j + dj;
					if(ni <0 || nj <0 || ni >= N || nj >= M) continue;
					if(mapp[ni][nj] == 1) continue;
					int D=1;
					while(1){
						ni += di; nj += dj;
						if(ni <0 || nj <0 || ni >= N || nj >=M) break;
						if(mapp[ni][nj] == 1){
							if( D >= 2){
//								cout << D;
								info.er = ni; info.ec= nj;
								if(disj.find(ni*M+nj) == disj.find(i*M+j)) break;
								info.len = D;
								cands.push(info);
							}
							break;
						}
						D++;
					}
				}

			}
		}
	}
	if(cands.size() == 0) return -1;
	else{
		ifo info = cands.top(); cands.pop();
		int a = info.sr*M+info.sc, b = info.er*M+info.ec;
//		cout << mapp[info.sr][info.sc] << ' ' <<mapp[info.er][info.ec] << endl;
//		cout << disj.find(a) << ' ' << disj.find(b) << endl;
		for(auto x : all_ones){
			if(disj.find(x) == disj.find(b)) disj.uni(a,b);
		}
		return info.len;
	}
}

void print(){
	cout << endl;
for(int i=0; i < N; i++){
  		for(int j=0; j < M; j++){
  			cout << disj.pa[i*M+j] << ' ' ;
  		}
  		cout << endl;
  	}
	cout << endl;
}

int32_t main(){ this_is_main_function
	cin >> N >> M;	
	for(int i=0; i < N; i++)
		for(int j=0; j < M; j++)
			cin >> mapp[i][j];
	disj.init(N,M);
//	for(int i=0; i < N; i++){
// 		for(int j=0; j < M; j++){
// 			cout << disj.pa[i*M+j] << ' ' ;
// 		}
// 		cout << endl;
// 	}
//
 	for(int i=0; i < N; i++){
 		for(int j=0; j < M; j++){
 			if(mapp[i][j] == 1){
				all_ones.push_back({i*M+j});
				for(int d=0; d < 4; d++){
					int ni = i+"2011"[d]-'1';
					int nj = j+"1102"[d]-'1';
					if(ni <0 || nj <0 || ni >= N || nj >= M) continue;
					if(disj.find(i*M+j) == disj.find(ni*M+nj)) continue;
					if(mapp[ni][nj] == 1){
//						cout << ni << ' ' << nj << endl;
						disj.uni(i*M+j, ni*M+nj);
					}
				}
			}
 		}
 	}
  	
	int ans=0;
	while(1){
		int k = add_edge();
//		cout << k << ' ';
//		print();
		if(k == -1) { cout << -1; exit(0);}
		else ans += k;
		if(all_same()) break;
	}
	cout << ans;

}

