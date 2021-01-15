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

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
#define int int64_t
// using long long as default, should consider TLE or RTE of it
void solve(){
    while(1){
        int n;
        cin >> n;
        if(!n) break;
        vector<int> v1,v2;
        for(int i=0; i < n; i++){
            int a; cin >> a;v1.push_back(a);
        }
        for(int i=0; i < n; i++){
            int a; cin >> a;v2.push_back(a);
        }
        int score1=0,score2=0;
        for(int i=0; i < n; i++){
            if(v1[i] ==1 && v2[i] == 2){
                score1 += 6;
            }else if(v1[i] == 2 && v2[i] == 1){
                score2 += 6;
            }else if(v2[i] -v1[i] == 1){
                score1 += (v2[i]+v1[i]);
            }else if(v1[i] - v2[i] ==1){
                score2  += (v2[i]+v1[i]);
            }else if(v1[i] > v2[i]){
                score1 += v1[i];
            }else if( v2[i] > v1[i]){
                score2+= v2[i];
            }
        }
        printf("A has %lld points. B has %lld points.\n",score1,score2);


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