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
// ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾





// ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾



int n,m,d;
int arr[20][20];
int vi[20][20];
struct archers{
    int a,b,c;
};
vector<archers> v;
void input(){
    cin >> n >> m >> d;
    ff(0,i,n-1){
        ff(0,j,m-1){
            cin >> arr[i][j];
        }
    }
}
void comb(){
    archers ac;
    ff(0,i,m-1){
        ff(i+1,j,m-1){
            ff(j+1,k,m-1){
                ac.a =i; ac.b = j; ac.c= k;
                v.pb(ac);
            }
        }
    }
}

void init(int one ,int two, int three){
    ff(0,i,m-1){
        arr[n][i] =0;
    }
    arr[n][one] =2;
    arr[n][two] =2;
    arr[n][three] =2;
}

int dxy[4][2] = {0,-1,1,0,-1,0,0,1};
vector<pipii> sp;


void go(int y,int x, int depth, int fy, int fx){
    if(vi[y][x]) return;
    if(depth > d ) return;
    if(arr[y][x] == 1){
        // cout << depth << '\n';
        sp.push_back({depth,{y,x}});
        // return;
    }
    // error(y,x);
    vi[y][x] = true;
    ff(0,i,3){
        int ny = y+dxy[i][0];
        int nx = x+dxy[i][1];
        int dd = abs(ny-fy) + abs(nx-fx);
        if(ny <0 || nx <0 || ny >=n+1 || nx >= m) continue;
        if(abs(ny-fy) + abs(nx-fx) >d) continue;
        go(ny,nx,dd,fy,fx);
    }
}


int attack(){
    int ret=0;
    set<pii> rs;
    ff(0,i,m-1){
        if(arr[n][i] == 2){
            // cout << i << " ";
            sp={};
            memset(vi,0,sizeof(vi));
            go(n,i,0,n,i);
            if(sp.size()) 
            {
                sort(all(sp),[](pipii a, pipii b){
                    if(a.F==b.F)return a.S.S < b.S.S;
                    return a.F < b.F;
                });
                // for(auto x : sp) cout << x.F << ' ' << x.S.F <<  " " << x.S.S<< ' ';
                // cout << '\n';
                int frY = sp[0].S.F;
                int frX = sp[0].S.S;
                // error(i,sp[0].F,frY,frX);
                rs.insert({frY,frX});
                // for(auto x : sp) cout << x.F << " ";
                // cout << '\n';
            }
        }
    }
    // cout << '\n';
    // cout << '\n'; 
    for(auto x :rs){
        // cout << x.F << " " << x.S << " ";
                arr[x.F][x.S] = 0;
    }
    ret += rs.size();
    return ret;
}

void mvDown(){
    rff(n-1,i,1){
        ff(0,j,m-1){
            arr[i][j] = arr[i-1][j];
        }
    }
    ff(0,i,m-1){
        arr[0][i] =0;
    }
}

bool check(){
    ff(0,i,n-1){
        ff(0,j,m-1){
            if(arr[i][j] !=0) return false;
        }
    }
    return true;
}


void print(){
    cout << '\n';
    ff(0,i,n){
        ff(0,j,m-1){
            cout << arr[i][j] << " ";
        }
    cout << '\n';
    }

}

int cpy[20][20];
void solve(){
    input();
    comb();
    // for(auto x : v)cout << x.a << " " << x.b << " " << x.c << "\n";
    ff(0,i,n-1) ff(0,j,m-1) cpy[i][j] = arr[i][j];
    int ret=0;
    ff(0,i,sz(v)-1){
        int SUM=0;
        archers ac = v[i];
        ff(0,i,n-1) ff(0,j,m-1) arr[i][j] = cpy[i][j];
        // error(SUM,ac.a,ac.b,ac.c);
        // cout << "@@@@@@@\n";
        while(1){
            if(check()) break;
            init(ac.a,ac.b,ac.c);
            int k = attack();
            SUM += k;
            // error(k);
            // print();
            mvDown();
        }
        // error(SUM);
        ret = max(ret,SUM);
    }
    cout << ret;
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