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
#define ff(a,i ,b) for(int i =(a); i <(b); ++i)
#define rff(a,i, b) for(int i= (a-1); i>=(b); --i)
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

    int a,b,c;
    while(1){
    cin >> a >> b >> c;
    if(!a && !b && !c) break;
    vector<int> v,v2;
    ff(0,i,a){
        int z; cin >> z; v.push_back(z);
    }
    ff(0,i,a-1){
        v2.push_back(abs(v[i]-v[i+1]));
    }
    // for(auto x : v2)cout << x << " ";

    int MAX=0;

    for(int i= b-1; i<= c-1; i++){
        MAX = max(v2[i],MAX);
        // error(v2[i],MAX);
    }
    
    for(int i=c-1; i>=b-1; i--){
        if(v2[i] == MAX) {
            cout << i+1 << '\n';
            break;
        }
    }
    }


    

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