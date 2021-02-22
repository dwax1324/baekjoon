// date: Mon Feb 22 22:19:04 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N;
	cin >> N;
	vector<int>v(N);
	for(int i=0; i < N; i++)
		cin >> v[i];
	int k; cin >> k;
	sort(all(v));
	if(find(all(v),k)!= v.end()){
		cout << 0; exit(0);
	}
	int A=0,B=0;
	for(int i=0; i < v.size()-1; i++){
		if(v[i] < k && v[i+1] > k) {
			A = v[i]+1; B = v[i+1]-1;
			break;
		}
	}
	int ans=0;
	if(A==0 && B==0){
		if(k < v[0]){
			A=1;B=v[0]-1;
		}
	}

	if(A&&B){
	int t1 = k-A;
	// if(t1 == 0) t1 =1;
	int t2 = B-k;
	// if(t2 == 0) t2 =1;
	ans =  t1*t2 + (B-A);
	}
	cout << ans;
}

