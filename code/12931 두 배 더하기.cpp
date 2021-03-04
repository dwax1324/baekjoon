// date: Thu Mar 4 15:33:44 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n; cin >> n;
    vector<int>v(n);
    for(int i=0; i < n; i++){
        cin >> v[i];
    }
    int cnt=0;
    auto minus = [&](){
        for(auto &x : v) {
            if(x%2 == 1){
                cnt++;x-=1;
            }
        }
        return true;
    };
    auto all0 = [&](){
        for(auto &x : v) if(x!=0) return false;
        return true;
    };
    auto dv2 = [&](){
        for(auto &x : v){
            x/=2;
        }
        cnt++;
    };

    while(!all0()){
        minus();
        if(all0())break;
        dv2();
    }
    cout << cnt;


}
}