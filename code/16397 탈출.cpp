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
    🎄2020.12.25🎄
    comment: 
    상황분기가 두개인데 
    continue를 위에서 써버려서 
    밑에까지 내려가지 못하게했다. 시간날림..
    if()대용으로 continue를 쓴다고 생각했었는데
    상황이 여러개면 또 그렇지만은 않다..
⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
#define int int64_t
// using long long as default, should consider TLE or RTE of it

bool vi[100000];

int getNum(int a){
    int tt=a;
    int temp=a;
    int cnt = 1;

    while(a){
        a/=10;
        cnt*=10;
    }
    cnt/=10;

    temp-=cnt;
    // error(tt,temp)
    return temp;
}

void solve(){
    int n,t,g;
    cin >> n >> t >> g;

    queue<pii> q;

    q.push({n,0});
    vi[n] = true;
    while(q.size()){
        int cur = q.front().F;
        int curCnt = q.front().S;
        // error(cur,curCnt);
        q.pop();
        if(curCnt > t ) break;
        if(cur == g){
            cout << curCnt;
            exit(0);
        }

        int ncur = cur+1;
        int ncnt = curCnt +1;
        
        // a
        if(!vi[ncur] && ncur <= 99999){
            q.push({ncur,ncnt});
            vi[ncur] = true;
        }
        // b
        ncur = cur *2;
        if(ncur > 99999) continue;
        ncur = getNum(ncur);
        if(vi[ncur]) continue;
            q.push({ncur,ncnt});
            vi[ncur] = true;
    }

    cout <<  "ANG";

}


auto main() -> int32_t {
    int32_t T = 1;
    misc(T);
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        // cout << "Data Set "<< i << ":\n";
        // cout << "case #" << i << ": ";
        solve();
    }
}

void misc(int32_t &T){
    fastio;
    debug;  
}