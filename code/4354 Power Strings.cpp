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
    comment: KMP의 실패(파이)함수의 활용
*/

int32_t main(){
    fastio;
    int fail[1000001];
    while(1){
    string s; cin >> s;
    if(s == ".") break;
        memset(fail,0,sizeof(fail));
        int N = s.size();
        for(int i=1,j=0; i < N; i++){
            while(j >0 && s[i] != s[j]) j= fail[j-1];
            if(s[i] == s[j]) fail[i] = ++j;
        }
        int q = fail[N-1], r= N-q;
        if(q == 0 || q%r ) cout << 1 << endl;
        else cout << q/r+1 << endl;
    }
}