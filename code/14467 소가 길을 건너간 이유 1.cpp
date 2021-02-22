// date: Mon Feb 22 23:24:02 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N; cin >> N;
	int arr[11];
	memset(arr,-1,sizeof(arr));
	int cnt=0;
	for(int i=0; i < N; i++){
		int a,b; cin >> a >> b;
		if(arr[a] != -1){
			if((arr[a] ^ b) ==1) {
				cnt++;
			}
			arr[a] = b;
		}else arr[a] = b;
	}
	cout << cnt;

}

