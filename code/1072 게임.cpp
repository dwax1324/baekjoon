// date: Sun Feb 28 20:15:46 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
    int X,Y; cin >> X >> Y;
    int K = Y*100/X;
    if(K >= 99) {cout << -1; return 0;}
    // @ function check
    auto check = [&](int mid){
        int T = ((Y+mid)*100)/(X+mid);
        return T > K;
    };
    // @ binary search
    int l = 1, r = 1e9+1;
    int mid;
    int ans = 5e9;
    while(l <= r){
        mid = (l+r)/2;
        if(check(mid)){
            r = mid -1;
            ans = min(mid,ans);
        }else{
            l = mid +1;
        }
    }
    cout << ans;

}