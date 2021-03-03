// date: Tue Mar 2 05:03:35 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M; cin >> N >> M;
    vector<int>v(N);
    for(int i=0; i < N; i++) cin >> v[i];
    sort(all(v));

    for(int i=0; i < M; i++){
        int a,b; cin >> a >> b;
        cout << upper_bound(all(v),b) - lower_bound(all(v),a) << '\n';
    }

}