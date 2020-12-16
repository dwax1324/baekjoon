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
#define ff(i, a, b) for(int i =(a); i <(b); ++i)
#define rff(i, a, b) for(int i= (a-1); i>=(b); --i)
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

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

void solve(){
    int n;
    cin >> n;
    int a=0,b=0,c=0;
    bool flag= false;
    ff(i,0,n){
        vector<int>v(2);
        cin >> v[0] >> v[1];
        sort(all(v));
        // error(v[0],v[1]);
        if((v[0] == 1 && v[1] == 3 )){
            a=1;
        }else if ((v[0] == 1 && v[1] == 4 )){
            b=1;
        }else if((v[0] == 3 && v[1] == 4 )){
            c=1;
        }else{
            flag= true;
        }
    }
    if(flag) cout << "Woof-meow-tweet-squeek";
    else if(a && b && c) cout << "Wa-pa-pa-pa-pa-pa-pow!";
    else cout << "Woof-meow-tweet-squeek";
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