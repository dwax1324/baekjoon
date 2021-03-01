// date: Mon Mar 1 17:34:33 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);

    int T; cin >> T; while(T--){
    
    // @ input
    int mapp[10][10];
    vector<pii> zeros;
    bool flag= false;
    for(int i=0; i < 9; i++)
        for(int j=0; j < 9; j++){
            char a; cin >> a;
            mapp[i][j] = a-'0';
            if(!mapp[i][j]) zeros.push_back({i,j});
        }


    // @ F check row
    auto check1 = [&](int r, int c){
        int arr[10] = {};
        for(int i=0; i < 9; i++){
            arr[mapp[r][i]]++;
        }
        for(int i=1; i<= 9; i++){
            if(arr[i] >1) return false;
        }
        return true;
    };

    // @ F check col
    auto check2 = [&](int r, int c){
        int arr[10] = {};
        for(int i=0; i < 9; i++){
            arr[mapp[i][c]]++;
        }
        for(int i=1; i<=9; i++){
            if(arr[i] > 1) return false;
        }
        return true;
    };

    // @ F check 3x3
    auto check3 = [&](int r, int c){
        int arr[10] = {};
        r = r/3*3, c = c/3*3;
        for(int i= r; i < r+3; i++){
            for(int j=c; j < c+3; j++){
                arr[mapp[i][j]]++;
            }
        }
        for(int i=1; i<=9; i++){
            if(arr[i] > 1) return false;
        }
        return true;
    };


    // @ F OK
    auto ok = [&](int r, int c){
        return (check1(r,c) && check2(r,c) && check3(r,c));
    };


    // @ F END

    auto END_THIS_PROBLEM = [&](){
        for(int i=0; i < 9; i++){
            for(int j=0; j < 9; j++){
                cout << mapp[i][j];
            }
            cout << '\n';
        }
    };
    

    // @ F dfs    
    function<void(int)> dfs =[&](int idx){
        if(idx == zeros.size()){
            END_THIS_PROBLEM();
            flag=true;
            return;
        }


        for(int i=1; i <= 9; i++){
            int r = zeros[idx].first , c = zeros[idx].second;
            mapp[r][c] = i;
            if(ok(r,c)){
                dfs(idx+1);
                if(flag)return;
            }
            mapp[r][c] = 0;
        }
    };

    dfs(0);
    if(!flag) cout << "Could not complete this grid.\n";
    cout << '\n';
    }
}