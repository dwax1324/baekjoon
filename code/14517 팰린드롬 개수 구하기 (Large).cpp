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
            2021.02.04 Thu
comment:
    dp 포함배제원리
/----------------------*/

const int mod = 10007;

string x;
int dp[1005][1005];

int f(int s, int e){
    if(s>e) return 0;
    int &ret = dp[s][e];
    if(ret!=-1) return ret;
    ret = f(s+1,e) + f(s,e-1)-f(s+1,e-1);
    if(x[s] == x[e]) ret += f(s+1,e-1)+1;
    return ret;

}

int32_t main(){ F
    cin >> x;
    memset(dp,-1,sizeof(dp));
    cout << f(0,sz(x)-1) << endl;

}