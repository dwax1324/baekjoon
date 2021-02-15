// date: Sat Feb 13 13:57:34 2021
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

int R,C,K;
vector<vector<int>> mapp(3,vector<int>(3));

void print();


bool rc_is_k(){
	if(R >= mapp.size() || C >= mapp[0].size()) return false;
	return mapp[R][C] == K;
}
bool cmp(pii a ,pii b){
	if(a.o1 == b.o1) return a.o2 < b.o2;
	return a.o1 < b.o1;
}
int MAXR=0,MAXC=0;
void go(){
	int r = mapp.size();
	int c = mapp[0].size();
	if( r >= c ) {
		for(int i=0; i < mapp.size(); i++){
			vector<pii> temp;
			unordered_map<int,int> mp;
			for(int j=0; j <mapp[i].size(); j++){
				int ele = mapp[i][j];
				if(ele == 0) continue;
				if(mp[ele]) mp[ele]++;
				else mp[ele] =1;
			}
			for(auto x : mp) temp.push_back({x.second,x.first});
			sort(all(temp),cmp);
			MAXR = max(MAXR,(int)temp.size()*2);
			MAXR = min(MAXR, 100);
			mapp[i].clear();
			for(int j=0; j < temp.size(); j++){
				mapp[i].push_back(temp[j].o2);
				mapp[i].push_back(temp[j].o1);
			}
		}
		for(int i=0; i < mapp.size(); i++){
			if(mapp[i].size() < MAXR){
				for(int j=0; j < mapp[i].size() - MAXR; j++){
					mapp[i].push_back(0);
				}
			}
		}

	}else{
		int idx =0;
		while(idx < c){
			unordered_map<int,int> mp;
			vector<pii> temp;
			for(int i=0; i < r; i++){
				int ele = mapp[i][idx];
				if(ele == 0) continue;
				if(mp[ele]) mp[ele]++;
				else mp[ele] =1;
			}
 			for(auto x : mp) temp.push_back({x.second,x.first});
 			int curr = temp.size()*2;
 			MAXC = max(MAXC, curr);
			MAXC = min(MAXC,100);
 			sort(all(temp),cmp);
			int diff = MAXC-mapp.size();
 			for(int i=0; i <diff ; i++){
 				mapp.push_back(vector<int>(c,0));
 			}
 			int t=0;
   			for(int i =0; i < curr; i+=2){
   				mapp[i][idx] = temp[t].o2;
				mapp[i+1][idx] = temp[t].o1;
				t++;
   			}
			for(int i= curr; i< MAXC; i++){
				mapp[i][idx] = 0;
			}
			idx++;
		}
	}
//	print();
}

void print(){
	cout << endl;
	for(auto x : mapp){
		for(auto y : x ){
			cout << y << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
int32_t main(){ this_is_main_function
	cin >> R >> C >> K; R--;C--;
	for(int i=0; i < 3; i++)
		for(int j=0; j < 3; j++)
			cin >> mapp[i][j];
//	print();
	for(int i=0; i <=100; i++){
		if(rc_is_k()){
			cout << i; exit(0);
		}
		go();
	}
	cout << -1;
}

