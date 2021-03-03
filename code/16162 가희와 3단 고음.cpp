// date: Wed Mar 3 23:02:06 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n,a,d; cin >> n >> a >> d;
    vector<int>v(n);
    for(int i=0; i < n; i++){
        cin >> v[i];
    }

    int ans=0;
    auto go = [&](int idx){
        int ret=0;
        int ta = a+d;
        for(int i=idx; i < n; i++){
            if(v[i] == ta){
                ret++;
                ta+=d;
            }
        }
        return ret;
    };
    for(int i=0; i < n; i++){
        if(v[i] == a){
            ans = go(i+1) + 1;
        }
    }
    cout << ans;

}
}