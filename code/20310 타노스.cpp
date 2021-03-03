// date: Thu Mar 4 05:13:47 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    string s; cin >> s;
    int cnt[2]={};
    for(auto x : s) cnt[x-'0']++;
    cnt[0]/=2;
    cnt[1]/=2;

    while(cnt[1]){
        for(int i=0; i <s.size(); i++){
            if(s[i] == '1'){
                s.erase(s.begin()+i);
                cnt[1]--;
                break;
            }
        }
    }
    while(cnt[0]){
        for(int i=s.size()-1; i >=0;i--){
            if(s[i] == '0'){
                s.erase(s.begin()+i);
                cnt[0]--;
                break;
            }
        }
    }
    cout << s;


}
}