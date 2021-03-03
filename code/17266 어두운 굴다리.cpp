// date: Tue Mar 2 04:14:59 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
    int N,M; cin >> N>> M;
    vector<int> v;
    for(int i=0; i < M; i++){
        int a; cin >> a;
        v.push_back(a);
    }

    int MAX =0;

    for(int i=0; i < v.size()-1; i++){
        // cout << v[i] << ' ' << v[i+1] << '\n';
        MAX = max(MAX,v[i+1]-v[i]);
    }
    cout << max({(MAX+1)/2 , v[0]-0 , N-v[v.size()-1]});



}