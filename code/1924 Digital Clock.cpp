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

    오늘 하루도 화이팅~
    rage, rage against the dying of the light
    2020.12.20

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

void solve(){
    for(int z =0; z <3 ;z++){
    string a,b;
    cin >> a >> b;
    int h = stoi(a.substr(0,2));
    int m = stoi(a.substr(3,2));
    int s= stoi(a.substr(6,2));
    int th = stoi(b.substr(0,2));
    int tm = stoi(b.substr(3,2));
    int ts= stoi(b.substr(6,2));


    int cnt=0;
    while(1){
        if(stoi(to_string(h) + to_string(m) + to_string(s)) %3 ==0){
            cnt++;
        }
        if(h == th && m == tm && s == ts) break;
        s++;
        if(s==60){
            s=0;
            m++;
        }
        if(m==60){
            h++;
            m=0;
        }

        if(h==24){
            h=0;
        }
    }
    cout << cnt << '\n';

    }
}


auto main() -> int {
    int T = 1;
    misc(T);
    for (int i = 1; i <= T; i++) {
        // cout << "case #" << i << ": ";
        solve();
    }
}

void misc(int &T){
    fastio;
//  debug;  
    // cin >> T;
}