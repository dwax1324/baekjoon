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
    2020.12.23
    comment: 
    재귀는 스택이다.
    스택은 거꾸로다.
    거리를 dp배열에 저장하면 거꾸로 저장된다.
    즉 호출한 자리에 거리가 저장되고 기저사례는 1이된다.
    반복문이랑 다르다.
    그래서 이미 방문했던 자리면 그 값을 넘겨주면 되는것이다.
    이미 뚫려있던(?) 자리기 때문에 그 값에 1만 더 더해주면 된다.

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
#define int int64_t
// using long long as default, should consider TLE or RTE of it



int n;
int arr[501][501];
int dp[501][501];


int dxy[4][2] = {1,0,-1,0,0,1,0,-1};
int go(int y, int x){
    int&ret = dp[y][x];
    if(ret!=-1) return ret;

    ret= 1;
    for(int i=0; i < 4;i++){
        int ny= y + dxy[i][0];
        int nx = x + dxy[i][1];
        if(ny <0 || nx < 0 || ny >=n || nx >= n) continue;
        if(arr[ny][nx] <= arr[y][x]) continue;
        ret = max(ret, go(ny,nx)+1);
    }
    return ret;
}



void solve(){
    cin >> n;
    for(int i=0; i < n ;i++){
        for(int j=0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    int ans =0;
    for(int i=0; i < n ;i++){
        for(int j=0; j < n; j++){
            ans = max(ans,go(i,j));
        }
    }
    cout << ans;



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