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

int vi[150][150];
int arr[150][150];
struct info{
	int y,x,l;
};
vector<info> v;
int n,m;

int dxy[4][2] = {1,0,-1,0,0,1,0,-1};
int go(int y, int x, int ty, int tx, int depth){
	if( !(y ==0 || y == n || x==0 || x == m)) return 1<<30;
	if(vi[y][x]) return 1<<30;
	if(y == ty && x == tx){

	// error(y,x,ty,tx,depth);
		return depth;	
	}
	vi[y][x]= true;
	int ret = 1<<30;
	for(int i=0; i <4 ;i++){
		int ny = y + dxy[i][0];
		int nx = x + dxy[i][1];
		if(ny <0 || nx <0 || ny >n || nx >m) continue;
		ret = min(ret,go(ny,nx,ty,tx,depth+1));	
	}
	return ret;
}
void solve(){
	cin >> m >> n;
	int k;
	cin >> k;
	vector<pii> coords;
	for (int i=0; i < k; i++){
		int a,b;
		cin >> a >> b;
		if(a== 1){
			arr[0][b] =1;
			coords.pb({0,b});
		}
		else if (a==2) {
			arr[n][b] =1;
			coords.pb({n,b});
		}
		else if (a==3 ) {
			arr[b][0] =1;
			coords.pb({b,0});
		}
		else {
			arr[b][m] =1;
			coords.pb({b,m});
			}
	}

	int sy,sx,z;
	cin >> sx >> z;
	if(sx ==1) sy =0, sx = z;
	else if (sx==2) sy = n, sx = z;
	else if (sx ==3) sy = z, sx = 0; 
	else sy = z , sx = m;
	// error(sy,sx);
	
	int ans=0;	
	for(int i=0; i < coords.size(); i++){
		memset(vi,0,sizeof(vi));
		ans += go(sy,sx,coords[i].F,coords[i].S,0);
	}
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
