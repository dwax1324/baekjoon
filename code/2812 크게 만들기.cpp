// date: Thu Mar 4 16:36:45 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n,k; cin >> n >> k;
    int K =k;
    string s; cin >> s;
    stack<int>stk;
    for(auto x : s){
        int X = x-'0';
        while(k && stk.size() && stk.top() < X){
            stk.pop();
            k--;
        }
        stk.push(X);
    }
    while(k){
        stk.pop();
        k--;
    }
    stack<int>stk2;
    while(stk.size()){
        stk2.push(stk.top());stk.pop();
    }
    while(stk2.size()){
        cout << stk2.top();
        stk2.pop();
    }

}
}