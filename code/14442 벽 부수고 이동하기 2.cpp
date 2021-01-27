#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.26 Tue
    comment: 
    BFS
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX =1001;
int N,M,K,map_[MAX][MAX],vi[11][MAX][MAX],vi2[MAX][MAX];

void solve(){
    cin >> N>> M >> K;

    for(int i=0; i < N; i++)
        for(int j=0; j < M; j++){
            char a; cin >> a; map_[i][j] = a=='1';
        }
    queue<tuple<int,int,int,int>> q;
    
    q.push({0,0,0,0});
    vi[0][0][0] = true;
    int ans=-1;

    for(;q.size();){
        int qs = q.size();
        for(int i=0; i < qs; i++){
            int r,c,wall,dist;
            tie(r,c,wall,dist) = q.front();
            if(r == N-1 && c == M-1){
                cout <<dist+1; exit(0);
            }
            q.pop();
            for(int d =0; d< 4; d++){
                int nr = r + "2011"[d] -'1';
                int nc = c + "1102"[d] -'1';
            // cout << r << " " << c << '\n';
                if(nr <0 || nc <0 || nr >= N || nc >=M) continue;
                if(wall< K && map_[nr][nc] == 1){
                    if(vi[wall+1][nr][nc]) continue;
                    q.push({nr,nc,wall+1,dist+1});
                    vi[wall+1][nr][nc] = true;
                    vi2[nr][nc] = true;
                }
                if(map_[nr][nc] == 1 || vi[wall][nr][nc]) continue;
                q.push({nr,nc,wall,dist+1});
                vi[wall][nr][nc] = true;
            }
        }
    }

    // for(int i=0; i < N; i++){
    //     for(int j=0; j < M; j++){
    //         cout << dist[0][i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    cout << ans;

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