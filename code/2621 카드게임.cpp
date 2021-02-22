// date: Mon Feb 22 19:02:03 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;

struct cd{
	char c;
	int n;
	cd(int c1, int n1):c(c1),n(n1){}
	bool operator<(const cd&a)const{
		return n < a.n;
	}
};
vector<cd>v;
int MAX=-1;
int q1(){
	set<char> s;
	int sq=0;
	for(int i=0; i<4; i++){
		sq += v[i+1].n - v[i].n;	
		s.insert(v[i].c);
	}
	if(sq == 4 && s.size()==1){
		return MAX+900;
	}
	return 0;
}
int q2(){
	int arr[10]={0};
	for(int i=0; i < 5; i++){
		arr[v[i].n]++;
	}
	for(int i=0; i < 10; i++)
		if(arr[i]==4) return i+800;
	return 0;
}
int q3(){
	int arr[10]={0};
	for(int i=0; i < 5; i++){
		arr[v[i].n]++;
	}
	int val3=0,val2=0;
	for(int i=0; i< 10; i++){
		if(arr[i]==2) val2=i;
		if(arr[i]==3){
			val3=i;
		}
	}
	if(val2&&val3)
		return val3 * 10 + val2 + 700;
	return 0;
}
int q4(){
	set<char>s;
	for(int i=0; i< 5; i++){
		s.insert(v[i].c);
	}
	if(s.size() == 1)
		return MAX+600;
	return 0;
}
// 5 sequential
// MAX + 500
int q5(){
	int sq=0;
	for(int i=0; i < 4; i++){
		sq+= v[i+1].n - v[i].n;
	}
	if(sq==4)
		return MAX+500;
	return 0;
}
// 3 num same 
// same num + 400
int q6(){
	int arr[10]={0};
	for(int i=0; i <5; i++){
		arr[v[i].n]++;
	}
	for(int i=0; i <10; i++){
		if(arr[i] ==3)
			return i + 400;
	}
	return 0;
}
// 2num same A , 2 num same B
// max(A,B) *10 + min(A,B)+300
int q7(){
	int arr[10]={0};
	for(int i=0; i < 5; i++) arr[v[i].n]++;
	int cnt2=0;
	vector<int>val;
	for(int i=0; i < 10; i++){
		if(arr[i] == 2){
			cnt2++;
			val.push_back(i);
		}
	}
	if(cnt2==2){
		sort(all(val));
		return val[1] *10 + val[0] + 300;
	}
	return 0;
}
// +200 on same number
int q8(){
	int arr[10]={0};
	for(int i=0; i <5; i++) arr[v[i].n]++;
	int cnt2=0;
	for(int i=0; i < 10; i++){
		if(arr[i] == 2){
			return i+200;
		}
	}
	return 0;
}
// max + 100
int q9(){
	return MAX+100;
}

int solve(){
	return max({q1(),q2(),q3(),q4(),q5(),q6(),q7(),q8(),q9()});
}


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
	for(int i=0; i < 5; i++){
		char a; int b; cin >> a >> b;
		MAX = max(b,MAX);
		v.push_back(cd(a,b));
	}
	sort(all(v));
	cout << solve();
}

