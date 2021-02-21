// date: Sun Feb 21 00:19:31 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

const int MAXN = 500001;
struct disj{
	int pa[MAXN];
	disj(){
		for(int i=0; i < MAXN; i++) pa[i]=i;
	}
	int find(int x) {return pa[x] = (x == pa[x] ?x: find(pa[x]));}
	bool uni(int a, int b){
		a = find(a); b= find(b);
		if(a==b) return false;
		pa[b] = a;
		return true;
	}
}disj;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	int N,M;
	cin >> N>> M;
	for(int i=0; i < M; i++){
		int a,b; cin >> a >> b;
		if(!disj.uni(a,b)) {
			cout << i+1; exit(0);
		}
	}
	cout << 0;

}

