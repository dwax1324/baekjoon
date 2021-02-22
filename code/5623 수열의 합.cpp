// date: Tue Feb 23 00:32:24 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int main(){
	int N; cin >> N;
	int arr[2][1001];
	for(int i=0; i < 2; i++)
		for(int j=0;j <N ;j++)
			cin >> arr[i][j];

	int a = (arr[0][1] + arr[0][2] -arr[1][2])/2;

	cout << a << ' ';
	for(int i=1; i < N; i++)
		cout << arr[0][i] - a << ' ';

}
