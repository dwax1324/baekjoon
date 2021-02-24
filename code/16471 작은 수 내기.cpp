// date: Wed Feb 24 17:00:52 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	deque<int> v(N),v2(N);
	for(int i=0; i< N; i++) cin >> v[i];
	for(int i=0; i< N; i++) cin >> v2[i];
	sort(all(v2)); 
	sort(all(v));
	int idx=0, idx2=0;
	int cnt=0;
	while(1){
		if(idx == N || idx2==N) break;
		if(v2[idx] > v[idx2]){
			idx++;idx2++;cnt++;
		}else{
			idx++;
		}
	}
	if(cnt >= (N+1)/2) cout << "YES";
	else cout << "NO";

}

