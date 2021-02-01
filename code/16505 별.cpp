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
// #define int int64_t
/*---------------------/
            2021.01.31 Sun
comment:
    
/----------------------*/

char arr[1<<11][1<<11];
void DQ(int r, int c, int n){
    if(n < 1){
        arr[r][c] = '*';
        return;
    }
    DQ(r,c,n/2);
    DQ(r,c+n/2,n/2);
    DQ(r+n/2,c,n/2);
}

int32_t main(){ F
    int k; cin >> k;
    if(k == 0) {
        cout << '*' << endl;
        exit(0);
    }
    int n = (1<<(k-1));

    for(int i=0; i < 2*n;i++)
        for(int j=0; j < 2*n; j++)
            arr[i][j] = ' ';

    DQ(0,0,n);
    DQ(0,n,n);
    DQ(n,0,n);

    for(int i=0; i < n*2;i++){
        for(int j=0; j < n*2-i; j++){
            cout << arr[i][j];
        }
        cout << '\n';
    }
}