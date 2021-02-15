// date: Fri Feb 12 01:29:21 2021
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


struct bottle{
	int curr,cap,a,b,c;
	bottle():curr(0),cap(0),a(0),b(0),c(0){}
};

int adj[3][3]={
	{0,1,1},
	{1,0,1},
	{1,1,0}
};

int32_t main(){ this_is_main_function
	int A,B,C;
	cin >> A >> B >>C;
	queue<bottle>q;
	bottle b;
	b.cap = C;
	b.curr = 2;
	q.push(b);
}

