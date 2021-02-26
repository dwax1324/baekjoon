// date: Thu Feb 25 22:08:03 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M;
	cin >> N >> M;
	char mapp[101][101];
	for(int i=0;i <N; i++){
		for(int j=0; j< M; j++){
			cin >> mapp[i][j];
		}
	}
	int arr[101] ={};
	int MAX=0;
	for(int i=0; i< N; i++){
		for(int j=0; j <M; j++){
			if(mapp[i][j] == '#'){
				arr[i]++;
				MAX = max(MAX,arr[i]);
			}
		}
	}
	int idx1,idx2;
	idx1=idx2=-1;
	for(int i=0; i < 101; i++){
		if(abs(arr[i]-MAX) ==1) {
			idx1= i;	
		}
		if(arr[i] == MAX) {
			idx2 = i;
		}
	}
	if(idx1 != -1 && idx1 > idx2){
		cout << "DOWN"; exit(0);
	}else if (idx1 != -1 && idx1 < idx2){
		cout << "UP"; exit(0);
	}
	memset(arr,0,sizeof(arr));
	MAX=0;
	for(int j=0; j < M; j++){
		for(int i=0; i < N; i++){
			if(mapp[i][j] == '#'){
				arr[j]++;
				MAX = max(arr[j],MAX);
			}
		}
	}
	idx1=idx2=-1;
	for(int i=0; i< 101; i++){
		if(abs(MAX-arr[i]) == 1) idx1 = i;
		if(MAX == arr[i]) idx2=i;
	}
	if(idx1 > idx2) cout << "RIGHT";
	else cout << "LEFT";
}
