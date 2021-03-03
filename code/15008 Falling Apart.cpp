// date: Wed Mar 3 23:57:40 2021
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
    sort(all(v),[](int a, int b){return a > b;});
    int A=0,B=0;
    for(int i=0; i < n; i++){
        if(i%2==0) A += v[i];
        else B+=v[i];
    }
    cout << A  << ' ' << B;

}
}