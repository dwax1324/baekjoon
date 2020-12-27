#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
void misc(int &t);
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.12.26
    comment: 
    3차원으로 시간을 조작하며 짜는 방법이 있고
    큐를 두개쓰면서 짤 수도 있다.

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
// #define int int64_t
// using long long as default, should consider TLE or RTE of it
#define pii pair<int,int>

int dxy[9][2]={
    {1,0},
    {1,-1},
    {1,1},
    {-1,0},
    {-1,1},
    {-1,-1},
    {0,0,}
};

char arr[10][10];
int n=8;

void mvDown(){
    char temp[10][10];

    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            temp[i][j] = arr[i][j];
        }
    }

    for(int i=1; i < n; i++){
        for(int j=0; j < n; j++){
            arr[i][j] = temp[i-1][j];
        }
    }

    for(int i=0; i < n; i++){
        arr[0][i] = '.';
    }
    
}


void solve(){
    for(int i=0; i <8 ;i++){
        for(int j=0; j< 8;j++){
            cin >> arr[i][j];
        }
    }
    queue<pii> q;
    q.push({7,0});
    int cnt=0;
    while(1){
        int vi[10][10];
        memset(vi,0,sizeof(vi));
        if(cnt++ > 10000){
            cout << 0;
            exit(0);
        }
        int s=1;
        queue<pii>temp;
        while(q.size()){
            if(cnt++ > 10000){
            cout << 0;
            exit(0);
            }

            int cury = q.front().first;
            int curx = q.front().second;
            q.pop();
            // cout << curx << " " << cury << " ";
            // cout << '\n';
            if(cury == 0 && curx == 7) {
                cout << 1;
                exit(0);
            }
            for(int i=0; i < 9; i++){
                int ny = cury + dxy[i][1];
                int nx = curx + dxy[i][0];
                if(ny <0 || nx <0 || ny >=n || nx>=n) continue;
                if(arr[ny][nx] == '#') continue;
                if(vi[ny][nx]) continue;
                temp.push({ny,nx});
                vi[ny][nx] = true;
            }
        }
        mvDown();
        while(temp.size()){
            int y = temp.front().first;
            int x = temp.front().second;
            if(arr[y][x] != '#'){
                q.push(temp.front());
            }
            temp.pop();
        }
    }


}

int32_t main() {
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