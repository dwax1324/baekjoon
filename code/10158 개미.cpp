// date: Mon Feb 22 18:41:20 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int w,h,p,q,t;
	cin >> w >> h >> p >> q >> t;
	int x,y;
	x = (p+t)/w;
	y = (q+t)/h;

	if(x%2 ==0){
		p = (p+t)%w;
	}else{
		p = w-((p+t)%w);
	}

	if(y%2==0){
		q = (q+t)%h;
	}else{
		q = h-((q+t)%h);
	}
	cout << p << ' ' << q;
}

