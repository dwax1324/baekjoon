#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define pii pair<int,int>
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.23 Sat
    comment: 
    유파/ bfs/ 분리집합
    유파로풀었다
    4번탐색 + 4번탐색이 중요한듯

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

char map_[1501][1501];
int map2[1501][1501];


const int off = 1501;
const int roff[4] = {1,-1, 0, 0};
const int coff[4] = {0, 0, 1,-1};

struct unionFind{
    int p[1000000];
    unionFind(){

        for(int i=0; i < 1000000; i++){
            p[i] =i;
        }

    }

    int f(int a){
        if(p[a] == a ) return a;
        return p[a] = f(p[a]);
    }

    void u(int a, int b){
        a = f(a);
        b = f(b);
        if( a== b ) return;
        // if(p[a] > p[b]){
        p[b] = a;
        // }else{
        // }
    }

};

void solve(){

    int n,m,sr=-1,sc,er,ec;
    cin >> n>> m;

    unionFind uf;
    queue<int> q;

    int z=1;
    for(int i=0; i< n; i++){
        for(int j=0; j < m; j++){
            cin >> map_[i][j];
            if(map_[i][j] == 'X') continue;
            map2[i][j] = z++;
            if(map_[i][j] == '.'){
                q.push(i*off + j);
            }
            if(map_[i][j] == 'L'){
                map_[i][j] = '.';
                q.push(i*off + j);
                if(sr == -1){
                    sr= i;
                    sc= j;
                }else{
                    er =i;
                    ec =j;
                }
            }

        }
    }

    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            if(map_[i][j] == '.')
                for(int d =0; d < 4; d++){
                    int nr = i + roff[d];
                    int nc = j + coff[d];
                    if(nr <0 || nc <0 || nr>= n || nc >= m || map_[nr][nc] == 'X') continue;
                    // cout << nr <<  "  " << nc << " " << map_[nr][nc] << "\n";
                    uf.u(map2[i][j], map2[nr][nc]);
                }
        }

    }

    int res =0;

//uf.f(map2[sr][sc]) == uf.f(map2[er][ec])
        // cout << uf.f(map2[sr][sc]) << " " <<  uf.f(map2[er][ec]);
    for(;uf.f(map2[sr][sc]) != uf.f(map2[er][ec]);res++){
        int qs = q.size();

        for(int i=0; i < qs; i++){
            int r = q.front() / off;
            int c = q.front() % off;

            q.pop();
            for(int d= 0; d < 4; d++){
                int nr = r + roff[d];
                int nc = c + coff[d];
                if(nr <0 || nc <0 || nr >= n|| nc >= m || map_[nr][nc] != 'X') continue;
                q.push(nr*off + nc);
                map_[nr][nc] = '.';
                map2[nr][nc] = map2[r][c];

                for(int dd= 0; dd < 4; dd++){
                    int nnr = nr + roff[dd], nnc = nc + coff[dd];
                    if(nnr <0 || nnc <0 || nnr >= n || nnc >=m || map_[nnr][nnc] == 'X') continue;
                    uf.u(map2[nr][nc] , map2[nnr][nnc]);
                }
            }

        }

    }

    cout << res;
}


int32_t main() {
    int t=1;
    fastio;
    // debug;
    {
        // cin >> t; 
        for(int i=1; i <= t; i++) solve();
    }
}

