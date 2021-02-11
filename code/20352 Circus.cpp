// Tue Feb  9 22:09:19 KST 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
// #define int int64_t

double PI = 3.141592;
// PIr^2 -> 2PIr
// let PIr^2 = a
// sqrt(a/PI) = r

void solve(){
	double a; cin >> a;
	double p = sqrt(4*PI*a);
	cout << fixed << setprecision(12) << p;

}


int32_t main(){ F int t=1;
// cin >> t;
while(t--) solve();}

