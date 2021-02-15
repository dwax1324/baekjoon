// date: Sat Feb 13 22:56:34 2021
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


int32_t main(){ this_is_main_function
int tt; cin >> tt; for(int ttt= 1; ttt<= tt; ttt++){
	string s; cin >> s;
	char a = tolower(s[s.size()-1]);
	if( a== 'y'){
		printf("Case #%d: %s is ruled by nobody.",ttt,s.c_str());
	}
	else if(a == 'a' || a == 'e' || a == 'i' || a== 'o' || a =='u')
		printf("Case #%d: %s is ruled by a queen.",ttt,s.c_str());
	else{
		printf("Case #%d: %s is ruled by a king.",ttt,s.c_str());
	}
	if(ttt != tt) puts("");
}
}

