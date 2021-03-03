// date: Thu Mar 4 03:43:32 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n; cin >> n;
    tii arr[25001];
    for(int i=0; i < n; i++){
        int a,b; cin >> a >> b;
        arr[i] = {a,b,i+1};
    }
    sort(arr,arr+n,[&](tii a, tii b){
        return double(get<0>(a)/double(get<1>(a)) > double(get<0>(b))/double(get<1>(b)));
    });
    vector<int> ans;
    int SUM=0;
    for(int i=0; i < 3; i++){
        SUM += get<1>(arr[i]);
        ans.push_back(get<2>(arr[i]));
    }
    cout << SUM<< '\n';
    for(auto x : ans)cout << x << '\n';

}
}