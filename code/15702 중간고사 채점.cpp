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

int arr[1000001];
int score[100001];
int vi[1000001];
void solve(){
    int n,m;
    cin >> n >> m;
    ff(1,i,n+1) cin >> arr[i];
    int MAX=0;
    ff(1,i,m+1){
        int a;
        cin >> a;
        vi[a] = true;
        ff(1,j,n+1){
            char b; cin >> b;
            if(b=='O') {
                score[a] += arr[j];
                // error(score[a],a);
                MAX = max(score[a],MAX);
            }
        }
    }

    // int MAX = *max_element(arr,arr+100001);

    ff(1,i,100001){
        if(vi[i] && score[i] == MAX){
            cout << i << " " << score[i];
            break;
        }
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