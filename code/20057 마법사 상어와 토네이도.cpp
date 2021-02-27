// date: Fri Feb 26 23:21:35 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	int mapp[700][700]={};
	int off = 10;
	for(int i=off; i < N+off; i++){
		for(int j=off; j < N+off; j++){
			cin >> mapp[i][j];
		}
	}
	int r = off + N/2, c = off + N/2;

	int ans =0;
	auto print =[&](){
		for(int i=off; i < off+N; i++){
			for(int j=off; j < off+N; j++)
				cout << mapp[i][j] << ' ';
			cout << endl;
		}
		cout << endl;
		return;
	};
	auto addAns =[&](int r, int c, int perc){
		if(r < off || c < off || r >= off+N || c >= off+N)  ans += perc;
	};
	auto add = [&](int& lamt,int r, int c,  int perc){
		mapp[r][c] += perc;
		lamt -= perc;
		addAns(r,c,perc);
	};
	bool flag =false;
	auto left = [&](int cnt){
		for(int i=0; i < cnt; i++){
			c--;
			int amt = mapp[r][c];
			int lamt = amt;
			mapp[r][c] =0;
			for(int j=-1; j<=1;j+=2){
				add(lamt,r+1*j,c+1,amt*1/100);
				add(lamt,r+1*j,c,amt*7/100);
				add(lamt,r+2*j,c,amt*2/100);
				add(lamt,r+1*j,c-1,amt*10/100);
			}
			add(lamt,r,c-2,amt*5/100);
			mapp[r][c-1] += lamt; addAns(r,c-1,lamt);
			if( r== off && c == off) {flag= true; break;}
		}
	};
	auto down = [&](int cnt){
		for(int i=0; i < cnt; i++){
			r++;
			int amt = mapp[r][c];
			mapp[r][c] =0;
			int lamt = amt;
			for(int j=-1; j<=1;j+=2){
				add(lamt,r-1,c+1*j,amt*1/100);
				add(lamt,r,c+1*j,amt*7/100);
				add(lamt,r,c+2*j,amt*2/100);
				add(lamt,r+1,c+1*j,amt*10/100);
			}
			add(lamt,r+2,c,amt*5/100);
			mapp[r+1][c] += lamt; addAns(r+1,c,lamt);
		}
	};
	auto right = [&](int cnt){
		for(int i=0; i < cnt; i++){
			c++;
			int amt = mapp[r][c];
			mapp[r][c] =0;
			int lamt = amt;
			for(int j=-1; j<=1;j+=2){
				add(lamt,r+1*j,c-1,amt*1/100);
				add(lamt,r+1*j,c,amt*7/100);
				add(lamt,r+2*j,c,amt*2/100);
				add(lamt,r+1*j,c+1,amt*10/100);
			}
			add(lamt,r,c+2,amt*5/100);
			mapp[r][c+1] += lamt; addAns(r,c+1,lamt);
		}
	};
	auto up = [&](int cnt){
		for(int i=0; i < cnt; i++){
			r--;
			int amt = mapp[r][c];
			mapp[r][c] =0;
			int lamt = amt;
			for(int j=-1; j<=1;j+=2){
				add(lamt,r+1,c+1*j,amt*1/100);
				add(lamt,r,c+1*j,amt*7/100);
				add(lamt,r,c+2*j,amt*2/100);
				add(lamt,r-1,c+1*j,amt*10/100);
			}
			add(lamt,r-2,c,amt*5/100);
			mapp[r-1][c] += lamt; addAns(r-1,c,lamt);
		}
	};
	int cnt=1;
	while(1){
		left(cnt);
		if(flag)break;
		down(cnt);
		cnt++;
		right(cnt);
		up(cnt);
		cnt++;
	}
	cout << ans;
}
