// date: Thu Mar 4 03:05:43 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n; cin >> n;
    if(n==2) {cout << 1; exit(0);}

    if(n%3 ==2) cout << n/3*7 + 1;
    else if(n%3 ==1) cout << n/3*7-7+4;
    else cout << n/3*7;

}
}