// date: Thu Mar 4 03:32:03 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
cin >> tt;
for(int tc=1;tc<=tt;tc++){
    string s; cin >> s;

    deque<char> q;
    for(auto x : s){
        if(q.size() == 0 || q[0] <= x){
            q.push_front(x);
        }else q.push_back(x);
    }
    cout << "Case #" << tc << ": ";
    for(auto x : q)cout << x;
    cout << '\n';

}
}