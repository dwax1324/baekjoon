// date: Tue Mar 2 03:59:30 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
    int N, M; cin >> N >> M;
    vector<int> v(N);
    for(int i=0; i < N; i++) cin >> v[i];

    int l = 1 , r = *max_element(all(v));

    auto check = [&](int mid){

        int cnt=0;
        for(int i=0; i < N; i++){
            cnt += v[i]/mid;
        }
        return cnt >=M;
    };
    int ans=0;
    while(l <=r ){
        int mid = (l+r)/2;

        if(check(mid)){
            l = mid+1;
            ans = max(mid,ans);
        }else{
            r = mid-1;
        }
    }
    cout << ans;

}