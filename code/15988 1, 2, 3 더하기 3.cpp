#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<int, char>
#define pipii pair<int, pii>
#define pll pair<long, long>
#define tiii tuple<int, int, int>
#define sz(x) (int)(x).size()
#define pb push_back
#define acc accumulate
#define ff(a,i ,b) for(int i =(a); i <= (b); ++i)
#define rff(a,i, b) for(int i= (a) ; i>=(b); --i)
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
        cout << '\n';                            \
    }
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << ' ';
    err(++it, args...);
}
void misc(int &t);
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.12.19
    dp
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int MOD = 1e9+9;
int dp[1000001];
int go(int n){
    int &ret = dp[n];
    if(n== 0) return 1;
    if(ret!= -1) return ret;

    ret = go(n-1);
    if(n>=2) ret = (ret+go(n-2))%MOD;
    if(n>=3) ret = (ret+go(n-3))%MOD;
    return ret;
}


void solve(){
    int t;
    int n;
    cin >>t;
    memset(dp,-1,sizeof(dp));
    while(t--){
        cin >> n;
        cout << go(n) << "\n";
    }

}


auto main() -> int {
    int t = 1;
    misc(t);
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << i << ": ";
        solve();
    }
}

void misc(int &t){
    fastio;
    debug;  
    // cin >> t;
}