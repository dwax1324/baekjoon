// date: Mon Feb 22 23:59:45 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int n,w;
	cin >> n >> w;
	vector<int> v(n);
	for(int i=0; i < n ;i++){
		cin >> v[i];
	}

	for(int i=0; i <n-1;){
		if(v[i] < v[i+1]){
			int g= w/v[i];
			w = w%v[i];
			while(1){
				i++;
				if(i == n-1 || v[i]>v[i+1]) break;
			}
			w += g*v[i];
		}else if(v[i] > v[i+1]){
			while(1){
				i++;
				if(i ==n-1 || v[i]<v[i+1]) break;
			}
		}else i++;
	}
	cout << w;

}

