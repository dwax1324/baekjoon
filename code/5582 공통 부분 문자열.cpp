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
// #define int int64_t
/*---------------------/
            2021.02.04 Thu
comment:
    LCS
/----------------------*/

int dp[4001][4001];
string a,b; 

int MAX=0;
int solve(int x, int y ){
    if(x == sz(a) || y == sz(b)) return 0;
    int &ret = dp[x][y];
    if(ret!=-1) return ret;
    ret = 0;
    solve(x,y+1);
    solve(x+1,y);
    if(a[x] == b[y]){
        ret = max(ret,solve(x+1,y+1)+1); 
        if(ret > MAX) MAX = ret;
    }
    return ret;
}


int32_t main(){ F
    cin >> a >> b;
    memset(dp,-1,sizeof(dp));
    solve(0,0);
    cout << MAX;

    // for(int i=0; i < sz(a); i++){
    //     for(int j=0; j < sz(b); j++){
    //         cout << dp[i][j];
    //     }
    //     cout << endl;
    // }
}