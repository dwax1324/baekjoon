#include <bits/stdc++.h>
using namespace std;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define DB freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
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
    구현
    
/----------------------*/



void print(char arr[][7]){
    cout << endl;
    for(int i=0; i <12; i++){
        for(int j=0; j < 6; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

char map1[13][7];
bool goDown(){
    char cpy[13][7];
    for(int i=0; i < 12;i++)
        for(int j=0; j < 6; j++)
            cpy[i][j] = map1[i][j];
    
    bool moved = false;
    for(int i=1; i < 12; i++){
        for(int j=0 ;j<6; j++){
            if(map1[i][j] == '.' && cpy[i-1][j] !='.'){
                map1[i-1][j] = '.';
                map1[i][j] = cpy[i-1][j];
                moved = true; 
            }
        }
    }
    // print(map1);
    return moved;
}


bool vi[13][8];

vector<pii> ret;
void dfs(int r, int c, char t){
    vi[r][c] = true;

    // ret.push_back({r,c});
    for(int d= 0; d < 4; d++){
        int nr = r + "2011"[d]-'1';
        int nc = c + "1102"[d]-'1';
        if(nr < 0 || nc <0 || nr >= 12 || nc >=6) continue;
        if(map1[nr][nc] != t ) continue;
        if(vi[nr][nc]) continue;
        dfs(nr,nc,t);
    }
    ret.push_back({r,c});
}

bool explode(){
    memset(vi,0,sizeof(vi));
    bool exploded=false;
    for(int i=0; i < 12; i++){
        for(int j=0; j < 6; j++){
            if(!vi[i][j] && map1[i][j] != '.'){
                ret={};
                dfs(i,j,map1[i][j]);
                // cout << tangled.size() << endl;
                // for(auto x : ret) cout << x.o1 << " " << x.o2 << endl;
                if(ret.size() >=4){
                    for(auto x : ret){
                        map1[x.o1][x.o2] = '.';
                        exploded= true;
                    }
                }
            }
        }
    }

    return exploded;
}



int32_t main(){ F
    for(int i=0; i < 12; i++){
        cin >> map1[i];
    }

    int ans=0;
    // goDown();
    // explode();
    // print(map1);

    // goDown();
    // goDown();
    // goDown();
    // explode();
    // print(map1);

    int cnt=0;
    while(1){
        if(cnt++ >20) break;
        // print(map1);
        if(goDown()) {
            cnt =0;
            continue;
        }
        if(explode()) {
            // print(map1);
            ans++;
            cnt=0;
        }
    }
    cout << ans;


}