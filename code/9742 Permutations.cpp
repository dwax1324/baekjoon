#include <bits/stdc++.h>
using namespace std;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
// #define int int64_t
/*---------------------/
            2021.02.01 Mon
comment:
    
/----------------------*/


int32_t main(){ F
  string s;int n;
  while(cin >> s >> n){
    cout << s << ' ' << n << " = ";
  do{
    if(n-- == 1) break;
  }while(next_permutation(all(s)));   
    if(n>0) cout << "No permutation" << endl;
    else cout << s << endl;
  }

}