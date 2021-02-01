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

const int N = 19;
int map1[N][N];

int dxy[4][2] ={
    {1,0},
    {1,1},
    {0,1},
    {-1,1}
};

bool notSafe(int r, int c){
    if(r <0 || c < 0 || r >= N || c >= N) return true;
    return false;
}

bool shouldPass(int r, int c, int roff, int coff ,int t){
    roff *= -1; coff *= -1;
    if(map1[r+ roff][c + coff]  == t) return true;
    return false;
}


bool check(int r, int c, int t){
    for(int d=0; d< 4; d++){
        int nr = r,nc= c, cnt=0, roff = dxy[d][0], coff=dxy[d][1];
        if(shouldPass(r,c,roff,coff,t)) continue;
        while(1){
            if(notSafe(nr,nc) || map1[nr][nc] != t)  break;
            cnt++; nr += roff; nc += coff;
        }
        if(cnt == 5) return true;
    }
    return false;
}

int32_t main(){ F
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            cin >> map1[i][j];
    
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++){
            if(map1[i][j] != 0 && check(i,j,map1[i][j])){
                cout << map1[i][j] << endl << i+1 << " " << j+1 << endl;
                exit(0);
            }
        }
    cout << 0;

}