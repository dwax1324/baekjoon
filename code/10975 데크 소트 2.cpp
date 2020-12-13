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




pii vi[2001];
deque<int> arr[1000];
vector<int>v;

bool checkFront(int a, int b,int c){
	if(a-b == -1) return true;
	for(int i=a+1; i <= b-1; i++){
		if(vi[i].F && vi[i].S > c) return false;
	}
	if(a < b)
	return true;
	else return false;
}

bool checkBack(int a, int b, int c){
	if(a-b == 1) return true;
	for(int i=b+1; i<= a-1; i++){
		if(vi[i].F && vi[i].S > c) return false;
	}
	if(a>b)
	return true;
	else return false;
}


void solve(){
	int n;
	cin >> n;
	v.resize(n);
	for(int i=0; i< n; i++){
		cin >> v[i];
		v[i] += 1000;
		vi[v[i]].F = v[i];
		vi[v[i]].S = i;
	}
	
	int k=0;
	int ans =1;
	arr[k].pb(v[0]);
	for(int i=1; i < n; i++){
		bool flag = false;
		for(int j=0; j <= k; j++){
			if(checkFront(v[i],arr[j][0], i)){
				arr[j].push_front(v[i]);
				flag = true;
				break;
			} 
			if(checkBack(v[i],arr[j].back(),i)){
				arr[j].pb(v[i]);
				flag = true;
				break;
			}
		}
		if(!flag) {
			k++;
			ans++;
			arr[k].pb(v[i]);
		}
	}
//		for(int j=0; j <= k; j++){
//			for(auto x : arr[j]) cout << x << " ";
//			cout << '\n';
//		}
	cout << ans;

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
