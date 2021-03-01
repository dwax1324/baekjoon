// date: Mon Mar 1 16:17:09 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
    int N; cin >> N;
    vector<pii> v(N);
    for(int i=0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(all(v));
    vector<int> stk;
    vector<pii> track;

    for(int i=0; i < N; i++){
        if(stk.empty() || stk.back() < v[i].second){
            track.push_back({stk.size(), v[i].first});
            stk.push_back(v[i].second);
        }else{
            auto iter = lower_bound(all(stk),v[i].second);
            *iter = v[i].second;
            track.push_back({iter - stk.begin(), v[i].first});
        }
    }    
    vector<int> ans;
    for(int i=track.size()-1, j = stk.size()-1; i >= 0; i--){
        if(track[i].first == j) j--;
        else ans.push_back(track[i].second);
    }
    sort(all(ans));
    cout << ans. size() << '\n';
    for(auto x : ans) cout << x << '\n';

}