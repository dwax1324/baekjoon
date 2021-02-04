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
    LCS
    
/----------------------*/

string a,b;
int dp[201][201];
int lcs(int i, int j){
    if(i == sz(a) || j == sz(b)) return 0;
    int &ret= dp[i][j];
    if(ret != -1) return ret;
    if(a[i] == b[j]){
        ret = max(ret,lcs(i+1,j+1)+1);
    }else{
        ret = max(lcs(i+1,j),lcs(i,j+1));
    }
    return ret;
}

int32_t main(){ F
    while(cin >> a >> b){
        memset(dp,-1,sizeof(dp));
        cout << lcs(0,0) << endl;
    }

}