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

/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

struct info{
	int a,b,c;
};



void solve() {
	int n;
	cin >> n;
	map<string,int> mp;
	while(n--){
		string s; cin >> s;
		mp[s] +=1;
	}
	int MAX=0;
	for(auto x : mp){
		MAX = max(MAX,x.second);
	}
	vector<string> vs;
	for(auto x :mp)
		if(x.second == MAX) vs.pb(x.first);

	sort(all(vs));
	cout << vs[sz(vs)-1] << " " << MAX;
}


auto main() -> int {
    fastio;
// debug;  // ‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®
    int t = 1;
//   cin >> t;  // ‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®‚ú®
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << i << ": ";
		// 
        solve();
    }
}

// do you read the problem properly?
// are the number of the input correct?
// are there edge cases?
// how about overflow?
// data structres properly reset between test cases?
// floating points?
// check if fastio is causing the problem
// use feynman algorithm


