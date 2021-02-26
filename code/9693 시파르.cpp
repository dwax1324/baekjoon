// date: Thu Feb 25 16:11:20 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int n;int t=1;
while(1){
	cin >> n;
	if(!n) break;
	int cnt5= 0;
	int z=n/5;
	for(;z;){
		cnt5+=z;
		z/=5;
	}

	cout << "Case #" << t++ << ": ";
	cout <<cnt5 << '\n';


}
}

