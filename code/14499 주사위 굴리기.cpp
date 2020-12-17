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
    구현
    주사위의 인덱스를 옮긴다
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<*/

int arr[7];
int arr2[7];
int MAP[21][21];
void solve(){
    int n,m,x,y,k;
    cin >> n >> m >> y >> x >> k;

    ff(0,i,n){
        ff(0,j,m){
        cin>> MAP[i][j];
        }
    }

    ff(0,i,k){
        int a;
        ff(0,j,6) arr2[j] = arr[j];
        cin >>a;
        int nx=x,ny=y;
        if(a== 4){
            ny +=1;
            if(ny <0 || nx <0 || ny >= n || nx >= m) continue;
            ff(0,j,3) arr[j] = arr2[j+1];
            arr[3] = arr2[0];
        }else if(a ==3){
            ny -=1;
            if(ny <0 || nx <0 || ny >= n || nx >= m) continue;
            ff(1,j,4) arr[j] = arr2[j-1];
            arr[0] = arr2[3];
        }else if (a==1){
            nx +=1;
            if(ny <0 || nx <0 || ny >= n || nx >= m) continue;
            arr[5] = arr2[1];
            arr[1] = arr2[4];
            arr[4] = arr2[3];
            arr[3] = arr2[5];
        }else if (a==2){
            nx -=1;
            if(ny <0 || nx <0 || ny >= n || nx >= m) continue;
            arr[5] = arr2[3];
            arr[1] = arr2[5];
            arr[4] = arr2[1];
            arr[3] = arr2[4];
        }
        // error(a, ny,nx);
        // ff(0,j,6) cout << arr[j] << " ";
        // cout << '\n';
        if(MAP[ny][nx] == 0) MAP[ny][nx] = arr[3];
        else {
            arr[3] = MAP[ny][nx];
            MAP[ny][nx] =0;
        }
        cout << arr[1] <<'\n';
        x = nx;
        y = ny;
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