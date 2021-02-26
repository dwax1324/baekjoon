// date: Thu Feb 25 13:58:08 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int go(int a, int m){
	int prevv =1, curr =1;
	int cnt=0;	
	while(1){
		int temp = (prevv+curr)% m;
		prevv = curr;
		curr = temp;
		cnt++;
		if(prevv ==1 && curr ==1) break;
	}
	return cnt;
}

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	 int N;
	 cin >> N;
	 for(int i=0; i< N; i++){
		int a,m; cin >> a >> m;
		cout << i+1 << ' ' << go(a,m) << '\n';
	 }
}

