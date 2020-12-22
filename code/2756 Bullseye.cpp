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
    comment :


⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
#define int int64_t
// using long long as default, should consider TLE or RTE of it
string symb = "!@#$%^&*()-+";
string s;
int n;



void solve(){
    double n;
    for(cin >> n ; n ; n--){
    double tot[2] ={0,0};
    for(int z= 0; z < 2; z++){
        for(double i=0; i < 3; i++){
            double a,b;
            cin >>a >> b;
            if(a*a +b*b <= 9){
                tot[z]+= 100;
            }else if(a*a +b*b <= 36){
                tot[z]+= 80;
            }else if(a*a +b*b <= 81){
                tot[z]+= 60;
            }else if(a*a +b*b <= 144){
                tot[z]+= 40;
            }else if(a*a +b*b <= 225){
                tot[z]+= 20;
            }
        }
    }
    if(tot[0] == tot[1]){
    printf("SCORE: %.0lf to %.0lf, TIE.\n",tot[0],tot[1]);
    }else if(tot[0] > tot[1]){
        printf("SCORE: %.0lf to %.0lf, PLAYER 1 WINS.\n",tot[0],tot[1]);
    }else if(tot[0] < tot[1]){
        printf("SCORE: %.0lf to %.0lf, PLAYER 2 WINS.\n",tot[0],tot[1]);
    }

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