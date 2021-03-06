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

void solve(){
    string s;
    getline(cin,s);
    int k=0;
    vector<string> v;
    string temp="";
    ff(i,0,sz(s)){
        if(s[i] == ' '){
            if(temp.size())
                v.push_back(temp);
            temp="";
        }
        temp+= s[i];
    }
    if (temp.size())
        v.push_back(temp);
    // for(auto x : v ) cout << x << " ";

    ff(i,1,sz(v)){
        if(v[i].size() == 1){
            cout << v[0] <<  " " << v[i] << ";\n";
        }else{
            reverse(all(v[i]));
            cout << v[0];
            bool flag= false;
            int idx=0;
            ff(j,0,sz(v[i])){
                if(!flag && ((v[i][j] <= 'z' && v[i][j] >= 'a') || (v[i][j] >= 'A' && v[i][j] <= 'Z'))){
                    flag =true;
                    cout << " ";
                    reverse(v[i].begin()+j,v[i].end());
                }
                if(v[i][j] == ',' || v[i][j] == ';' || v[i][j] == ' ') continue;
                else if(v[i][j] == ']') cout << '[';
                else if(v[i][j] == '[') cout << ']';
                else cout << v[i][j];
            }
            cout << ";\n";

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