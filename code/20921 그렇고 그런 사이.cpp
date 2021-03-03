// date: Thu Mar 4 01:35:40 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n,k; cin >> n >> k;
    vector<int>arr(n);
    for(int i=0; i < n; i++){
        arr[i] = i+1;
    }
    if(k==0){
        for(auto x : arr)cout << x << ' ';
        exit(0);
    }
    int cnt=0;
    for(int i=n-1; i >=0; i--){
        for(int j=n-1; j >= n-i; j--){
            swap(arr[j],arr[j-1]);
            cnt++;
            if(cnt == k) goto eol;
        }
    }
eol:
    for(auto x : arr) cout << x << ' ';

}
}