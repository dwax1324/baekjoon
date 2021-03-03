// date: Wed Mar 3 15:40:13 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n, i, a, b[1000005], c;
    cin >> n;
    for (i = 0; i < n; i++){
        cin >> a;
        if(b[a] == 0) {
            c++;    
            b[a-1]++;
        }
        if(b[a] >=1){
            b[a]--;
            b[a-1]--;
        }
    }
    cout << c << endl;

}
}