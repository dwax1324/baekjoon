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
#define ff(begin, i, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S secon
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

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int n,a,b;
vector<string> v;
char go(int y, int x){
	for(int i=0; i< a ;i++){
		for(int j=x; j < x+b; j++){
			if(v[i][j] != '?') return v[i][j];
		}
	}
	return '?';
}

void solve(){
	cin >> n >> a >> b;
	for(int i=0; i < a; i++){
		string s;
		cin >> s;
		v.pb(s);
	}

	for(int i=0; i < b*n; i+=b){
		cout << go(0,i);
	}
}

auto main() -> int {
    fastio;
// debug;  // ‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®
    int t = 1;
//	cin >> t;  // ‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << i << ": ";
        solve();
    }
}
d
