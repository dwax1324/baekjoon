// date: Thu Mar 4 05:00:13 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i < n; i++){
        cin >> v[i];
    }
    sort(all(v));
    int ans;
    if(v.size()%2){
        int m= v[v.size()-1];
        int N = (v.size()-2);
        for(int i=0; i< v.size()/2; i++){
            m = max(m,v[i]+v[N-i]);
        }
        ans = m;
    }else{
        int m = -1;
        for(int i=0; i < v.size()/2 ; i++){
            m = max(m,v[i]+v[v.size()-1-i]);
        }
        ans = m;
    }
    cout << ans;

}
}