#include <bits/stdc++.h>
using namespace std;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
// #define int int64_t
/*---------------------/
            2021.02.05 Fri
comment:
    LCS + backtrack
    
/----------------------*/

string a, b;
int dp[41][41];
int lcs(int p, int q){
    if(p == sz(a) || q == sz(b)) return 0;
    int &ret = dp[p][q];
    if(ret != -1) return ret;
    ret=0;
    if(a[p] == b[q]){
        ret = max(ret, lcs(p+1,q+1)+1);
    }else{
        ret = max({ret,lcs(p,q+1),lcs(p+1,q)});
    }
    return ret;
}


int32_t main(){ F
    cin >> a >> b;
    memset(dp,-1,sizeof(dp));
    lcs(0,0);
    // for(int i=0; i < a.size(); i++){
    //     for(int j=0; j < b.size(); j++){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int i,j; i=j=0;
    while(i < a.size() && j < b.size()){
        if(a[i] == b[j]){
            cout << a[i];
            i++;j++;
        }else{
            if(dp[i+1][j] >= dp[i][j+1]) i++;
            else j++;
        }
    }
}