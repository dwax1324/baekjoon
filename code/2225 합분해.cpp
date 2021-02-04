#include <bits/stdc++.h>
using namespace std;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 s.econd
#define endl '\n'
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define int int64_t
/*---------------------/
            2021.02.04 Thu
comment:
    dp
    
/----------------------*/


int n,k;
int dp[201][201];
int mod = 1e9;
int solve(int choose, int sum){
    if(choose == k){
        if(sum == n)
            return 1;
        return 0;
    }
    int&ret = dp[choose][sum];
    if(ret!= -1) return ret;
    ret =0;
    for(int i=0; i <= n; i++){
        if(sum+i <= n)
            ret += solve(choose+1,sum+i);
    }
    return ret %= mod;
}


int32_t main(){ F
    cin >> n >> k;
    memset(dp,-1,sizeof(dp));
    cout << solve(0,0);
}