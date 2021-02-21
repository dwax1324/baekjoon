// date: Sun Feb 21 02:01:54 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int X,Y; cin >> X >> Y;
	int l =1, r = 1e9;
	double curr = Y*100/X;
	cout << curr;
	if(curr == 99) cout << -1;
	int tar = curr+1;
	int mid;
	while(1){
		mid = (l+r)/2;
		double ntar = (mid+Y*100)/(X+mid);
		cout << ntar << ' ' << mid << '\n';
		if(ntar == tar)break;
		if(ntar > tar){
			l = mid+1;	
		}else if(ntar < tar)
			r = mid-1;
	}
	cout << mid;
}

