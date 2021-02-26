// date: Thu Feb 25 17:05:33 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M; cin >> N >> M;
	vector<int> v(N);
	for(int i=0; i < N; i++){
		cin >> v[i];
	}
	
	int off=0;
	for(int i=0; i < M; i++){
		int a,b,c; cin >> a;
		if(a==1){
			cin >> b >> c; b--;
			v[(b+off)%N] += c;
		}else if (a==2){
			cin >> b;
			off -= b;
			if(off <0) off = off+N;
		}
		else{
			cin >> b;
			off += b;
			if(off>=N) off%=N;
		}
//	cout << off << endl;	
//	for(auto x : v) cout << x << ' ';
//	cout << endl;
	}
	int cnt=0;
	for(int i=off;cnt++ != N;i = (i+1)%N){
		cout << v[i] << ' ' ;
	}
}

