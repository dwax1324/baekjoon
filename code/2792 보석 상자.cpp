// date: Tue Mar 2 03:26:07 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
    int N, M; cin >> N >> M;
    vector<int> v(M);
    int MIN = 2e9;
    for(int i=0 ; i < M; i++){
        cin >> v[i];
        MIN = min(MIN,v[i]);
    }
    int l = 1 , r = MIN+1;


    // @ F check
    auto check = [&](int mid){
        int cnt=0;
        for(int i=0; i < M; i++){
            cnt += v[i]/mid;
            if(v[i]%mid) cnt++;
        }
        return cnt <= N;
    };

    // @ binary_search
    int mid;
    int ans=2e9;
    while(l <= r){
        mid = (l+r)/2;

        if(check(mid)){
            r = mid-1;
            ans = min(mid,ans);
        }else{
            l = mid+1;
        }
    }
    cout << ans;


}