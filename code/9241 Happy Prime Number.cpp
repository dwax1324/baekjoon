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
#define ff(i, a, b) for(int i =(a); i <(b); ++i)
#define rff(i, a, b) for(int i= (a-1); i>=(b); --i)
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

bool vi[1000001];
void seive(int a){
    for(int i=2; i*i<= a; i++){
        if(vi[i]) continue;
        for(int j=i*i; j <=a ; j+=i){
            vi[j] = true;
        }
    }
}

auto go(int a){
    int rvi[10001];
    memset(rvi,0,sizeof(rvi));
    bool flag = false;

    while(1){
        int b= 0;
        while(a){
            int k = (a%10) * (a%10);
            b+= k;
            a/=10;  
        }
        // error(b);
        if(b==1) flag= true;
        if(rvi[b]) break;
        rvi[b]=1;
        a=b;
    }

    return flag;
}


void solve(){
    int n;
    cin >> n;
    seive(n);
    for(int i=7; i <= n; i++){
        if(vi[i]) continue;
        if(go(i)) cout << i << '\n';
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