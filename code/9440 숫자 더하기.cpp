// date: Wed Mar 3 21:27:58 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
//cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n;
    while(1){
    cin >> n;
    if(!n)break;
    vector<int> v;
    int cnt_zeros=0;
    for(int i= 0; i < n; i++){
        int a; cin >> a; 
        if(!a)cnt_zeros++;
        else v.push_back(a);
    }
    string a="",b="";
    sort(all(v));
    for(int i=0; i < v.size(); i++){
        if(i%2==0) a+= to_string(v[i]);
        else b+= to_string(v[i]);
    }
    for(int i=0; i < cnt_zeros; i++){
        if(a.size() == b.size()){
            a.insert(a.begin()+1,'0');
        }else if(a.size() > b.size()){
            b.insert(b.begin()+1,'0');
        }else if(a.size() < b.size()){
            a.insert(a.begin()+1,'0');
        }
    }
    cout << stoi(a)+stoi(b) << '\n';
    }
}
}