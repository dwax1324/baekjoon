// date: Wed Mar 3 23:34:19 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n; cin >> n;
    vector<tii> v;
    for(int i=0; i < 3*n; i++){
        int a,b; cin >> a >> b;
        v.push_back({a,b,i});
    }
    sort(all(v));
    for(int i=1; i <= n*3; i++){
            cout << get<2>(v[i-1])+1 << ' ';
        if(i%3==0) cout << '\n';
    }


}
}