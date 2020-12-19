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
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.12.19

    구현
    
    자신이 이동한방향을 벡터에 저장한다.
    벡터를 스택에 넣고 팝하면서 90도 바꿔준다.

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int n;
int arr[200][200];
int dxy[4][2] = {1,0,-1,0,0,1,0,-1};

int cntSquare(){
    int ret=0;
    for(int i=0; i <100; i++){
        for(int j=0; j< 100;j++){
            if(arr[i][j] && arr[i+1][j] && arr[i+1][j+1] && arr[i][j+1])ret++;
        }
    }
    return ret;
}

void print(){
    cout << '\n';
    for(int i=0; i < 101; i++){
        for(int j=0; j < 101; j++){
            cout << arr[i][j] ;
        }
        cout << '\n';
    }

}


pii rotate(int y ,int x){
    if(y == 1 && x== 0){
        return {0,1};
    }else if(y == 0 && x==1){
        return {-1,0};
    }else if (y == -1 && x== 0){
        return {0,-1};
    }else if (y== 0 && x == -1){
        return {1,0};
    }
    return {0,0};
}

void go(int y, int x, int d, int g, int cur){
    arr[y][x] =cur;
    int fy = y, fx = x;
    vector<pii> ops;
    if(d ==0){
        arr[y][x+1] =cur;
        ops.pb({0,1});
        x++;
    }else if(d==1){
        arr[y-1][x] =cur;
        ops.pb({-1,0});
        y--;
    }else if(d==2){
        arr[y][x-1] = cur;
        ops.pb({0,-1});
        x--;
    }else if(d==3){
        arr[y+1][x] =cur;
        ops.pb({1,0});
        y++;
    }
    if(g==0) return;
    for(int i=1; i<= g; i++){
        stack<pii> stk;
        for(auto z : ops){
            stk.push({z.F,z.S});
        }

        while(stk.size()){
            pii ncoords = rotate(stk.top().F,stk.top().S);
            stk.pop();
            ops.pb(ncoords);
            int ny = y + ncoords.F;
            int nx = x + ncoords.S;
            arr[ny][nx] = cur;
            y = ny; x = nx;
        }
    }
}

void input(){
    cin >> n;
    for(int i=0; i < n; i++){
        int x,y,d,g;
        cin >> x >> y >> d >> g;
        go(y,x,d,g,i+1);
    }
    // print();
    cout << cntSquare();
}

void solve(){
    input();

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