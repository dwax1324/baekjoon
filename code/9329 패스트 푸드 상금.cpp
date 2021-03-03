// date: Thu Mar 4 02:38:46 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);int tt = 1;
cin >> tt;
for(int tc=1;tc<=tt;tc++){

    int n,m; cin >> n >> m;
    vector<int> arr[11]={};
    for(int i=0; i < n; i++){
        int a,b; cin >> a;
        for(int j=0; j < a; j++){
            cin >> b; b--;
            arr[i].push_back(b);
        }
        cin >> b;
        arr[i].push_back(b);
    }
    sort(arr,arr+n,[&](vector<int> a, vector<int>b){
        return a[a.size()-1] > b[b.size()-1];
    });
    int A[31]={};
    for(int i=0; i < m; i++){
        cin >> A[i];
    }
    int ans=0;
    
    while(1){
        bool changed = false;
        for(int i=0; i < n; i++){
            bool ok = true;
            for(int j=0; j < arr[i].size()-1; j++){
                if(A[arr[i][j]] == 0) ok = false;
            }
            if(ok){
                changed = true;
                for(int j=0; j < arr[i].size()-1; j++){
                    A[arr[i][j]]--;
                }
                ans += arr[i][arr[i].size()-1];
                break;
            }
        }
        if(!changed)break;
    }
    cout << ans << '\n';


}
}