// date: Mon Feb 22 23:43:16 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	vector<string>v = {"pi", "ka", "chu"};
	string q;
	cin >> q;

	for(auto it= q.begin(); it!= q.end();){
		
		if(v[0][0] == *it && v[0][1] == *(it+1)){
			it++;it++;	
		}
		else if(v[1][0] == *it && v[1][1] == *(it+1)){
			it++;it++;
		}else if(v[2][0] == *it && v[2][1] == *(it+1) && v[2][2] == *(it+2)){
			it++;it++;it++;
		}else{
			cout << "NO"; exit(0);
		}
	}
	cout <<	"YES";
	
}

