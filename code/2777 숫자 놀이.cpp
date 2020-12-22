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
    2020.12.22
    comment: 

    그리디

    십진수를 쓰기 때문에 두자리수는 제외하고
    2,3,5,7로 소인수분해를한다.
    (2 3개), (남은2,3을 2개), (5 1개),(7 1개)을 하나의 자리수로 생각한다.

    1~10에대한 예외처리를 해줘야한다.
⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
#define int int64_t
// using long long as default, should consider TLE or RTE of it
void solve(){
    vector<int> v={2,3,5,7};
    
    int t;
    cin >> t;
    while(t--){
        int a;
        cin >> a;
        if(a<10){
            cout << 1 << '\n';
            continue;
        }
        int z =a;
        vector<int> v2;
        int ans=0;
        while(a!=1){
            bool flag = false;
            for(int i=0; i < v.size(); i++){
                if(a%v[i] == 0) {
                    flag=true;
                    v2.pb(v[i]);
                    a/=v[i];
                    break;
                }
            }
            if(a == 1) break;
            if(!flag) {
                ans=-1;
                break;
            }
        }
        if(ans == -1){
            cout << ans << "\n";
            continue;
        }
        ans=0;
        int cnt2=0,cnt3=0,cntelse=0;
        for(int i=0; i < v2.size(); i++){
            if(v2[i] ==2) cnt2++;
            else if(v2[i]==3) cnt3++;
            else cntelse++;
        }

        ans += cnt2/3;
        cnt2 %=3;
        cnt3 += cnt2;
        ans += cnt3/2;
        cnt3 %=2;
        if(cnt3) ans+= 1;
        ans += cntelse;
        // error(z);
        // for(auto x : v2)cout << x << " ";
        // cout << '\n';
        cout  <<  ans << '\n';
}


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