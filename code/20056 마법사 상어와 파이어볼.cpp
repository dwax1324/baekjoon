// date: Mon Feb 22 10:26:09 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int N,M,K;
// fireball
struct fb{
	int m,s,d;
	fb():m(-1),s(-1),d(-1){}
	fb(int m1, int s1, int d1):m(m1),s(s1),d(d1){}
};

// use copymap to avoid map overlap calc
// use deque to avoid overlapping infos
// eg) use infos base on cpymapp(reference it, val never change)
// push back new infos and pop front old infos from map
deque<fb> mapp[51][51];
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
void query1_move(deque<fb> cpmp[51][51],int r, int c){
//	cout << "@@";
	//cout <<r << ' ' << c << '\n';
	int sz = cpmp[r][c].size();
	for(int i=0; i < sz; i++){
		int m =cpmp[r][c][i].m;
		int d =cpmp[r][c][i].d;
		int s =cpmp[r][c][i].s;
		mapp[r][c].pop_front();
		int dr = dx[d] * s;
		int dc = dy[d] * s;
		int nr = r + dr, nc =  c + dc;
		nr%=N; nc%=N;
		if(nr <0) nr += N;
		if(nc <0) nc += N;
		mapp[nr][nc].push_back(fb(m,s,d));
	}
}


void query1(){
	deque<fb> cpmp[51][51];
	for(int i=0; i < N; i++)
		for(int j=0; j < N; j++)
			cpmp[i][j] = mapp[i][j];
	for(int i=0; i < N; i++){
		for(int j=0; j < N; j++){
			if(cpmp[i][j].size() > 0 ){
				query1_move(cpmp,i,j);
			}
		}
	}

}
void query2_merge(int r, int c){
	int totM =0,totS=0;
	bool allEven=true, allOdd=true;
	// cout << r << ' ' << c << '\n';
	for(auto x : mapp[r][c]){
		totM += x.m; totS += x.s;
		// cout << x.d << ' ';
		if(x.d%2) allEven=false;
		else allOdd = false;
	}
	// cout << totM << ' ';
	// cout << '\n';
	totS = totS/mapp[r][c].size();
	mapp[r][c].clear();
	totM = totM/5;
	if(totM == 0) return;
	if(allEven || allOdd){
		for(int d=0; d<8; d+=2){
			// cout << d << ' ';
			mapp[r][c].push_back(fb(totM,totS,d));
		}
	}else{
		for(int d=1; d<8; d+=2){
//			cout << d << ' ';
			mapp[r][c].push_back(fb(totM,totS,d));
		}
	}
}

void query2(){
	for(int i=0; i < N;i++){
		for(int j=0; j < N; j++){
			if(mapp[i][j].size() >=2)
				query2_merge(i,j);
		}
	}
}
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> N>> M>> K;
	
	for(int i=0; i < M; i++){
		int r,c,m,s,d;
		cin >> r >> c >> m >> s >> d;
		r--;c--;
		mapp[r][c].push_back(fb(m,s,d));
	}

	for(int i=0; i < K; i++){
		query1();
		query2();
	}
	
	int ans=0;
	for(int i=0; i < N; i++){
		for(int j=0; j <N ;j++){
			for(auto x : mapp[i][j]){
				ans += x.m;
			}
		}
	}
	cout << ans;

}

