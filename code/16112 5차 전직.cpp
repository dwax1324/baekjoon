// date: Wed Mar 3 22:25:01 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n,m; cin >> n >> m;
    vector<int>v(n);
    for(int i=0; i < n;i++){
        cin >> v[i];
    }
    sort(all(v));
    int t=1;
    int ans=0;
    for(int i=1; i< n; i++){
        ans += v[i]*t;
        if(i< m) t++;
    }
    cout <<ans;

}
}