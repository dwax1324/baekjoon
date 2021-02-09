// Tue Feb  9 21:19:24 KST 2021
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

void solve(){
	double a,b;
	cin >> a >> b;
	double c = sqrt(a*a+b*b);
	cout << setprecision(7) << fixed << a+b-c;
}


int32_t main(){ F int t=1;
// cin >> t;
while(t--) solve();}

