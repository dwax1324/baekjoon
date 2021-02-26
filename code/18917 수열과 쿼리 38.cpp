// date: Thu Feb 25 21:57:41 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int M;
	cin >> M;
	vector<int> v;
	int xr = 0;
	int sm = 0;
	for(int i=0;i < M; i++){
		int a,b; cin >> a;
		if(a==1){
			cin >> b;
			sm += b; xr ^= b;
		}else if (a==2){
			cin >> b;
			sm -= b; xr ^= b;	
		}else if(a==3){
			cout << sm << '\n';
		}else{
			cout << xr << '\n';
		}
	}
}

