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

int map1[20][20];
int dxy[8][2] = {
    {-1,0},
    {-1,-1},
    {0,-1},
    {1,-1},
    {1,0},
    {1,1},
    {0,1},
    {-1,1},
};

bool notSafe(int r, int c){
    if(r <0 || c<0 || r >= 19 || c >= 19 ) return true;
    return false;
}
bool shouldPass(int r,int c,int roff, int coff){
    roff *= -1; coff*= -1;
    if(map1[r + roff][c + coff] == map1[r][c]) return true;
    return false;
}

bool realCheck(int r, int c, int curr){

    for(int d =4 ; d < 8 ; d++){

        int nr=r,nc=c,cnt=0;
        int roff = dxy[d][0];
        int coff = dxy[d][1];
        if(shouldPass(r, c, roff, coff)) continue;
        while(1){

            if(notSafe(nr,nc) || map1[nr][nc] != curr) break;
            cnt++; nr+= roff; nc+=coff;

        }
            if(cnt == 5) return true;

    }

    return false;


}

bool check(){
    for(int i=0; i < 19; i++){
        for(int j=0; j < 19 ;j++){
            if(map1[i][j] != 0 && realCheck(i,j,map1[i][j])) {
                return true;
            }
        }
    }
    return false;
}


int32_t main(){ F
    int n; cin >> n;
    vector<int> ans;
    for(int i=1; i <= n; i++){
        int a,b; cin >> a >> b; a--;b--;
        if(i%2){
            map1[a][b] = 2;
        }else{
            map1[a][b] = 1;
        }
        if(check()){
            ans.push_back(i);
        }
    }
    if(ans.size()) cout << ans[0];
    else cout << -1;
}