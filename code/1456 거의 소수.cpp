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

const int MAX = 10000001;
bool vi[MAX];
vector<ull> v;
void seive(){
    for(int i=2; i < MAX; i++){
        if(vi[i]) continue;
        v.pb(i);
        for(int j=2*i; j< MAX; j+=i){
            vi[j] = true;
        }   
    }
}


void solve(){
    seive();
    ull a,b;
    cin >> a >> b;
    cout << v.size();
    ull cnt=0;
    for(int i=0; i < sz(v); i++){
        ull t= v[i];
        while(t <= b/v[i]){
            t *= v[i];
            if(t >= a) cnt++;
        }
    }
    // cout << cnt;
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