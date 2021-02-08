// date: Mon Feb 8 00:19:24 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
#define int int64_t

const int MAX=1000001;
int dp[MAX];
void solve(){
    dp[1] = 1;
    for(int i=2; i< MAX; i++){
        for(int j=1; j*i < MAX; j++){
            dp[i*j] += i;
        }
        dp[i] += dp[i-1]+1;
    }

    int t; cin >>t; while(t--){
        int n; cin >> n;
        cout << dp[n] << endl;

    }

}


int32_t main(){ F int T=1;
// cin >> t;
for(int tt=0;tt<T;tt++) {solve(); }}