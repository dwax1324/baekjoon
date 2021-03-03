// date: Wed Mar 3 14:18:42 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0); int tt = 1;
cin >> tt;
while(tt--){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i < n; i++){
        cin >> v[i];
    }
    sort(all(v));
    deque<int> q;

    for(int i=0; i < v.size(); i++){
        if(i%2==0) q.push_back(v[i]);
        else q.push_front(v[i]);
    }
    int ans=0;
    for(int i=0; i < q.size()-1; i++){
        ans = max(ans,abs(q[i]-q[i+1]));
    }
    // for(auto x : q ) cout << x << ' ';
    ans = max(ans,abs(q[0]-q[q.size()-1]));
    cout << ans << '\n';
}
}