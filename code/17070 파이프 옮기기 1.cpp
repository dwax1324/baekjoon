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
    2020.12.24
    comment: 
        dp 구현

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
#define int int64_t
// using long long as default, should consider TLE or RTE of it


int arr[20][20];
int dp[20][20][3];
int n;
// prev  가로 0 세로 1 대각2
int go(int y, int x , int prev){
    if(y>n || x >n ) return 0;
    if(y== n&& x == n) return 1;
    int&ret = dp[y][x][prev];
    if(ret != -1) return ret;

    ret = 0;
    if(prev==0){
        if(!arr[y][x+1]){
            ret += go(y,x+1,0);
        }
        if(!arr[y][x+1] && !arr[y+1][x+1] && !arr[y+1][x]){
            ret += go(y+1,x+1,2);
        }
    }
    if(prev == 1){
        if(!arr[y+1][x]){
            ret += go(y+1,x,1);
        }
        if(!arr[y][x+1] && !arr[y+1][x+1] && !arr[y+1][x]){
            ret += go(y+1,x+1,2);
        }
    }
    if(prev ==2){
        if(!arr[y+1][x]){
            ret += go(y+1,x,1);
        }
        if(!arr[y][x+1]){
            ret += go(y,x+1,0);
        }
        if(!arr[y][x+1] && !arr[y+1][x+1] && !arr[y+1][x]){
            ret += go(y+1,x+1,2);
        }
    }
    return ret;

}


void solve(){
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for(int i=1; i<= n; i++){
        for(int j=1; j<= n; j++){
            cin >> arr[i][j];
        }
    }
    arr[1][1]= 1;
    arr[1][2] =1;

    cout << go(1,2,0);

}

auto main() -> int32_t {
    int32_t T = 1;
    misc(T);
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        // cout << "Data Set "<< i << ":\n";
        // cout << "case #" << i << ": ";
        solve();
    }
}

void misc(int32_t &T){
    fastio;
    debug;  
}