// date: Thu Feb 25 22:36:22 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;
string A[] = {"Re","Pt","Cc","Ea","Tb","Cm","Ex"};
string B[] = {"Re","Pt","Cc","Ea","Tb","Cm","Ex"};
int arr[10];
map <string,int> mp;
int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	string s;
	int tot =0;	
	while(cin >> s){
		tot++;
		if(mp[s])mp[s]++;
		else mp[s] =1;
	}
	for(auto x : mp){
		for(int i=0; i < 7; i++){
			if(A[i] == x.first) A[i] = to_string(x.second);
		}
	}
	for(int i=0; i < 7; i++){
		if(A[i][0] >'9' || A[i][0] <'0') A[i] = "0";
	}
	for(int i=0; i < 7; i++){
		cout << fixed << setprecision(2) << B[i] << ' ' << A[i] << ' ' << (double)stoi(A[i])/(double)tot << '\n'; 
	}
	cout << "Total " << tot << " 1.00";
}

