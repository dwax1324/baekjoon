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
    comment: 지문을 잘읽어야혀~

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
#define int int64_t
// using long long as default, should consider TLE or RTE of it
void solve(){
    string s1,s2;
    cin >> s1 >> s2;
    int sh = stoi(s1.substr(0,2));
    int sm = stoi(s1.substr(3,2));
    int ss = stoi(s1.substr(6,2));
    int eh = stoi(s2.substr(0,2));
    int em = stoi(s2.substr(3,2));
    int es = stoi(s2.substr(6,2));
    if(s1 == s2){
        cout << "24:00:00";
        return;
    }

    int cnt=0;
    while(1){
        if(sh == eh && sm == em && ss == es){
            break;
        }
        // error(sh, sm, ss);
        ss++;
        if(ss== 60){
            ss=0;
            sm++;
        }
        if(sm ==60){
            sm=0;
            sh++;
        }
        if(sh == 24){
            sh= 0;
        }
        cnt++;
    }
    int gs = cnt%60;
    cnt /=60;
    int gm = cnt%60;
    int gh = cnt/60;

    // cout << gh << " " << gm << " " << gs;
    printf("%02lld:%02lld:%02lld",gh,gm,gs);

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