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
    2021.01.22 Fri
    comment: 

    트리의 지름 2차원
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

void solve(){
    
    int T;
    cin >> T;
    while(T--){

        int r,c,sr=-1,sc;
        cin >> c >> r;
        bool map[1001][1001];
        for(int i=0; i < r; i++){
            string s;
            cin >> s;
            for(int j=0; j < c; j++)
                map[i][j] = s[j] == '#';
        }

        for(int i=1 ;i< r-1; i++){
            for(int j=1; j< c-1; j++){
                if(map[i][j]) continue;

                int cnt =0;
                for(int dir=0; dir<4; dir++){
                    int nr = i+"2011"[dir]-'1';
                    int nc = j+ "1102"[dir]-'1';
                    if(!map[nr][nc]) cnt++;
                }
                if(cnt <=1){
                    sr = i;
                    sc = j;
                    break;
                }
            }
            if(sr >= 0) break;
        }

        for(int k=0; k< 2; k++){
            bool vi[1001][1001] ={0};
            int dist[1001][1001];
            queue<int> Q;
            vi[sr][sc] = true;

            for(int i=0; i < r; i++)
                fill(dist[i], dist[i]+c, 1<<30);
            dist[sr][sc] = 0;

            Q.push(sr*1000+sc);

            int res;

            for(res =0; !Q.empty(); res++){
                int qSize = Q.size();

                for(int i=0; i < qSize; i++){
                    int r = Q.front()/1000, c = Q.front()%1000;
                    Q.pop();
                    for(int dir =0; dir<4 ; dir++){
                        int nr = r+ "2011"[dir]-'1';
                        int nc = c+ "1102"[dir]-'1';
                        if(map[nr][nc] || vi[nr][nc]) continue;
                        vi[nr][nc] = true;
                        dist[nr][nc] = res+1;
                        sr = nr;
                        sc = nc;
                        Q.push(nr*1000+nc);
                    }
                }

            }

            if(k) cout << "Maximum rope length is " << res-1 <<".\n";
        }



    }

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