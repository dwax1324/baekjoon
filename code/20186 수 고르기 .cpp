#include <bits/stdc++.h>
using namespace std;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define int int64_t
/*---------------------/
            2021.01.30 Sat
comment:
    정렬
/----------------------*/

int cal(int a){

    if(a < 1 ) return a;
    return a + cal(a-1);
}


int32_t main(){ F
    int n,m; cin >> n >> m;
    vector<int>v(n);
    for(int i=0; i < n; i++) cin>> v[i];
    sort(rall(v));
    int tot =0;
    for(int i=0; i < m; i++){
        tot += v[i];
    }
    cout << tot-cal(m-1);
}