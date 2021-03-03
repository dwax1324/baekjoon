// date: Thu Mar 4 02:01:38 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n; cin >> n;
    int arr[50001]={};
    int MAX=0;
    for(int i=0; i < n; i++){
        int a; cin >> a;
        arr[a]++;
        MAX = max(arr[a],MAX);
    }
    cout << MAX;

}
}