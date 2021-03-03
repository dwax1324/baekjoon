// date: Wed Mar 3 20:38:17 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n,s,r; cin >> n >> s >> r;
    int broken[11]={};
    int oneMore[11]={};
    for(int i=0; i <s; i++) {
        int a; cin >> a;
        broken[a]=1;
    }
    for(int i=0; i < r; i++){
        int a; cin >> a;
        if(broken[a]){
            broken[a] = 0;
        }else{
            oneMore[a] = 1;
        }
    } 
    
    for(int i=1; i <= n; i++){
        if(i!=1) if(oneMore[i] == 1 && broken[i-1] == 1){
                oneMore[i] = 0;
                broken[i-1] = 0;
        }
        if(i!= n) if(oneMore[i] == 1 && broken[i+1] == 1){
                oneMore[i] = 0;
                broken[i+1] = 0;
        }
    }
    int cnt=0;
    for(int i=1; i <= n; i++){
        if(broken[i]) cnt++;
    }
    cout << cnt;

}
}