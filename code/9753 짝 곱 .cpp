// date: Tue Mar 2 05:25:45 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;



int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
vector<int> v;
vector<int>v2;
auto seive = [&](){
    vector<bool>vis(100000,0);
    for(int i=2; i<= 100000; i++){
        if(vis[i])continue;
        v.push_back(i);
        vis[i] = true;
        for(int j= i*2; j<= 100000;j+=i){
            vis[j] = true;
        }
    }
};
seive();

for(int i=0; i < v.size(); i++)
    for(int j=i+1; j < v.size(); j++){
            if(v[i] * v[j] <= 100001)
                v2.push_back(v[i]*v[j]);
    }

sort(all(v2));

int tt; cin >> tt; while(tt--){
    int n; cin >> n;
    cout << *lower_bound(all(v2),n) << '\n';
}
}