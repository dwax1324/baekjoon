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

    2020.12.21

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
#define int int64_t
// using long long as default, should consider TLE or RTE of it


double WR[3] = {4.5,150,200};
double L[3] = {6.0, 300,500};
double Q[3] = {5.0,200,300};

void solve(){
    double a,b,c;

    while(1){
        cin >> a >> b >> c;
        bool flag =false;
        if(a==0 && a==b&& b==c) break;
            if(a <= WR[0] && b>= WR[1] && c>= WR[2]){
                cout << "Wide Receiver ";
                flag=true;
            }
            if(a <= L[0] && b>= L[1] && c>= L[2]){
                cout << "Lineman ";
                flag=true;
            }
            if(a <= Q[0] && b>= Q[1] && c>= Q[2]){
                cout << "Quarterback ";
                flag=true;
            }
        if(!flag) cout << "No positions";
        cout << '\n';
    }

}


auto main() -> int32_t {
    int32_t T = 1;
    misc(T);
    for (int i = 1; i <= T; i++) {
        // cout << "case #" << i << ": ";
        solve();
    }
}

void misc(int32_t &T){
    fastio;
    debug;  
    // cin >> T;
}