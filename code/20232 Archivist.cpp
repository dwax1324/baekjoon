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

map<int,string> mp={
{1995, "ITMO"},
{1996, "SPbSU"},
{1997, "SPbSU"},
{1998, "ITMO"},
{1999, "ITMO"},
{2000, "SPbSU"},
{2001, "ITMO"},
{2002, "ITMO"},
{2003, "ITMO"},
{2004, "ITMO"},
{2005, "ITMO"},
{2006, "PetrSU, ITMO"},
{2007, "SPbSU"},
{2008, "SPbSU"},
{2009, "ITMO"},
{2010, "ITMO"},
{2011, "ITMO"},
{2012, "ITMO"},
{2013, "SPbSU"},
{2014, "ITMO"},
{2015, "ITMO"},
{2016, "ITMO"},
{2017, "ITMO"},
{2018, "SPbSU"},
{2019, "ITMO"},
};

void solve(){
    int a;
    cin >> a;
    cout<< mp[a];
  
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