// date: Sun Feb 28 20:00:19 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M; cin >> N >> M;
    vector<int> v(N);
    for(int i=0; i < N; i++) cin >> v[i];

    // @ func check
    auto check = [&](int mid){
        int cnt=1;
        int curr=mid;
        for(auto x : v){
            if(x > mid) return false;
            if( curr < x){
                curr = mid;
                cnt++;
            }
            curr -= x;
        }
//        cout << cnt << ' ' << M << '\n';
        return (cnt <= M);
    };
    
    // @ binary search
    int l= 1, r = accumulate(all(v),0);

    int ans = 2e9;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            r = mid-1;
            ans = min(ans,mid);
        }else{
            l = mid+1;
        }
    }
    cout << ans;

}