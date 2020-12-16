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

char arr[51][51];

int odd[6][2] = {1, 0, -1, 0, 0, 1, 0, -1, -1, 1, 1, 1};  
int even[6][2] = {1, 0, -1, 0, 0, 1, 0, -1, 1, -1, -1, -1};

void solve(){
    int n,m;
    cin >> n >> m;
    ff(0,i,n){
        ff(0,j,m){
            cin >> arr[i][j];
        }
    }
    int cnt=0;
    ff(0,i,n){
        ff(0,j,m){
            if(arr[i][j] == '#'){
                ff(0,k,6){
                    int ny,nx;
                    if(i% 2==0){
                        ny = i + even[k][0];
                        nx = j + even[k][1];
                    } else{
                        ny = i + odd[k][0];
                        nx = j + odd[k][1];
                    }
                    if(ny <0 || nx < 0 || ny >= n || nx >= m) continue;

                    if(arr[ny][nx] == '.') {
                        cnt++;
                    }
                }
            }
        }
    }
        
    cout << cnt;

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