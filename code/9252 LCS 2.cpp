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
    LCS + 역추적
    
/----------------------*/


int dp[1001][1001];
int32_t main(){ F

    string a,b;cin >> a >> b;
    a.insert(a.begin(),'0');
    b.insert(b.begin(),'0');
    for(int i=1; i < sz(a); i++){
        for(int j=1; j< sz(b);j++){
            dp[i][j] = max({dp[i-1][j],dp[i][j-1],dp[i][j]});
            if(a[i] == b[j])
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
        }
    }

    int ans =dp[sz(a)-1][sz(b)-1];
    if(!ans){
        cout << 0; exit(0);
    }
    cout << ans << endl;
    int i=sz(a)-1,j=sz(b)-1;
    stack<char> stk;
    while(dp[i][j] !=0){
        if(a[i] == b[j]){
            stk.push(a[i]);
            i--;j--;
        }else{
            if(dp[i-1][j] == dp[i][j]){
                i--;
            }else{
                j--;
            }
        }
    }
    while(stk.size()){
        cout << stk.top();stk.pop();
    }
}
