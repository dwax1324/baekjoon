// date: Thu Mar 4 01:18:55 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){
    vector<double> v;
    int n; cin >> n; for(int i=0; i < n; i++){
        int a; cin >> a; v.push_back(a);
    }
    sort(all(v));
    for(int i=0; i < v.size()-1; i++){
        v[v.size()-1] += v[i]/2.0;
    }
    cout << fixed << setprecision(6) << v[v.size()-1];

}
}