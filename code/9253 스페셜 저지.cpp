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
    comment: kmp algorithm
*/

bool KMP(string S, string W){
    int fail[200001] ={0};
    for(int i=1,j=0; i< W.size(); i++){
        if(j > 0 && W[i] != W[j]) j = fail[j-1];
        if(W[i] == W[j]) fail[i] = ++j;
    }

    for(int i=0,j=0; i < S.size(); i++){
        while( j >0 && S[i] != W[j]) j = fail[j-1];
        if(S[i] == W[j]){
            if(j == W.size()-1){
                return true;
            }else j++;
        }
    }    
    return false;
}


int32_t main(){
    string a,b,c; cin >> a >> b >> c;

    bool ans(0);
    ans |= KMP(a,c);
    ans |= KMP(b,c);
    ans ? cout << "YES" : cout << "NO";

}