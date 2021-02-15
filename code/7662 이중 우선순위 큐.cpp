// date: Sat Feb 13 02:22:25 2021
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

// depq

int32_t main(){ this_is_main_function
int tt; cin >> tt; while(tt--){
	int n; cin >> n;
	multiset<int> s;
	for(int i=0; i < n; i++){
		char a; int b;
		cin >> a >> b;
		if(a == 'I'){
			s.insert(b);	
		}else{
			if(b == -1){
				if(s.size())
					s.erase(s.begin());
			}else{
				if(s.size())
					s.erase(--s.end());
			}
		}
	}

	if(s.size()) cout << *(--s.end()) << ' ' << *(s.begin()) << endl;
	else cout << "EMPTY" << endl;
}
}

