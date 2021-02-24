// date: Thu Feb 25 01:09:16 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	string s; cin >> s;
	string t ="quack";

	int ans=0;
	while(1){
		int idx=0;
		for(int i=0; i < s.size(); i++){
			if(idx == 5){ans++; break;}
			if(s[i] == 	t[idx]){
				s.erase(s.begin()+i);
				i--;
				idx++;
			}
		}
		if(idx <5) break;
	}
	cout << ans;

}

