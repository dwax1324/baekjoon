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


int n;
int arr[21][21];
int dist[21][21];
struct shark{
    int y,x,size,curSize;
};
int ans=0;

void print(){
    cout << "########################\n";
    ff(0,i,n-1){
        ff(0,j,n-1){
            cout << arr[i][j];
        }
        cout << '\n';
    }
    cout << "########################\n\n";

}
shark sk;
void input(){
    cin >> n;
    ff(0,i,n-1) ff(0,j,n-1) {
        cin>>arr[i][j];
        if(arr[i][j] == 9){
            sk.y =i; sk.x = j;
            arr[i][j] = 0;
        }
    }
    sk.size=2; sk.curSize= 0;
}

int dxy[4][2] = {0,1,0,-1,1,0,-1,0};
void bfs(){
    queue<shark> q;
    q.push(sk);
    bool flag= false;
    while(1){
        vector<pair<shark,int>> v;
        memset(dist,-1,sizeof(dist));
        dist[q.front().y][q.front().x] =0;
        // error(q.front().y, q.front().x,q.front().size);
        if(flag)
            q.front().curSize++;
        if(q.front().curSize == q.front().size){
            q.front().curSize =0 ;
            q.front().size ++;
        }
        // error(q.front().curSize,q.front().size);
        // print();
        arr[q.front().y][q.front().x] =0;
        while(q.size()){
            int curX = q.front().x;
            int curY = q.front().y;
            int size = q.front().size;
            int curSize = q.front().curSize;
            // error(curY,curX, dist[curY][curX]);
            q.pop();
            ff(0,i,3){
                int ny = curY + dxy[i][0];
                int nx = curX + dxy[i][1];
                if(ny <0 || nx <0 || ny >=n || nx >= n) continue;
                if(dist[ny][nx] != -1) continue;
                if(arr[ny][nx] > size) continue;
                if(arr[ny][nx] != 0 && arr[ny][nx]  < size){
                    dist[ny][nx] = dist[curY][curX] + 1;
                    shark ns = {ny,nx,size,curSize};
                    v.push_back({ns,dist[ny][nx]});
                }else{
                    dist[ny][nx] = dist[curY][curX] + 1;
                    shark ns = {ny,nx,size,curSize};
                    q.push(ns);
                }
            }
        }
        // for(auto x :v )cout << x.F.y << " " << x.F.x << " ";
        if(!v.size()) {
            return;
        }
        flag=true;
        sort(all(v),[](pair<shark,int> a, pair<shark,int> b){
            if(a.S == b.S){
                if(a.F.y == b.F.y) return a.F.x < b.F.x;
                return a.F.y < b.F.y;
            }
            return a.S < b.S;
        });
        ans += v[0].second;
        q.push(v[0].F);

    }
}

void solve(){
    input();
    bfs();
    cout << ans;
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