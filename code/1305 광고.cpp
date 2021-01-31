#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
typedef pair<int,int> pi;
typedef tuple<int,int,int> tii;
// #define int int64_t
/*
    2021.01.28 Fri
    comment:   
    Pi[N] : 처음 위치부터 현재까지 잘 맞춰져 온 문자 길이 라고 이해하시면
    N-Pi[N-1] : 최대가 N이고 잘 맞춰져 온 거리 만큼 빼주면 그 나머지가 답이 될수 있는 가장 짧은 길이라고 판단됩니다.

*/

int fail[10000001];
int32_t main(){
    int L;cin >> L ; string s; cin >> s;
    for(int i=1,j=0; i< L; i++){
        while(j && s[i] != s[j]) j= fail[j-1];
        if(s[i] == s[j]) fail[i] = ++j;
    }
    cout << L-fail[L-1];

}