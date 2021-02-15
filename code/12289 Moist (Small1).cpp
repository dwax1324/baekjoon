// date: Sat Feb 13 22:40:49 2021
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
int tt; cin >>tt; for(int t=1; t<= tt; t++){
	int n; cin >> n;
	vector<string> v;
	cin.ignore();
	for(int i=0; i < n; i++){
		string t;
		getline(cin,t);
		v.push_back(t);
	}
	int ans =0;
	// while(1){
		bool not_sorted= false;
		for(int i=0; i < v.size()-1; i++){
			if(v[i] > v[i+1] ) {
				swap(v[i],v[i+1]);
				ans ++;
				not_sorted = true;
			}
		}
//		if(!not_sorted) break;
	// }
	cout << "Case #" << t << ": ";
	cout << ans << endl;
}
}

