// date: Sat Feb 13 23:53:07 2021
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
#define ull long long
ull N,A,B,C,D;

int32_t main(){ this_is_main_function
	cin >> N >> A>> B >> C >> D;
	if(A * D < C * B) {
		swap(A,C);
		swap(B,D);
	}
	ull ret = (N+A-1) / A *B;
	ull n = A/gcd(A,C);
	for(ull i=1; i< n; i++){
		ull t = i*D;
		if(N -C*i > 0 ) t += (N - C*i + A-1)/A *B;
		ret = min(ret,t);
	}
	cout << ret;
}

