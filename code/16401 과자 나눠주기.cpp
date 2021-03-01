// date: Tue Mar 2 03:50:14 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M; cin >> N>> M;
    vector<int> v(M);
    for(int i=0; i < M; i++) cin >> v[i];

    int l= 1, r = *max_element(all(v));


    auto check = [&](int mid){
        int cnt=0;
        for(int i=0; i < M; i++){
            cnt += v[i]/mid;
        }
        return cnt >=N;
    };

    int ans=-1;
    while(l <= r){
        int mid = (l+r)/2;

        if(check(mid)){
            l = mid+1;
            ans = max(ans,mid);
        }else{
            r = mid-1;
        }
    }
    cout << ans;

}