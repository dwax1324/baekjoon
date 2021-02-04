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
            2021.02.04 Thu
comment:
    bfs
    
/----------------------*/
int n,m;
int cnt =0;
char mapp[21][21];
vector<pii> coords;

int bfs(int a, int b){
    bool vi[21][21];
    memset(vi,0,sizeof(vi));
    queue<pii> q;
    q.push({coords[a].o1,coords[a].o2});
    q.push({coords[b].o1,coords[b].o2});
    vi[coords[a].o1][coords[a].o2] = true;
    vi[coords[b].o1][coords[b].o2] = true;
    int rcnt = cnt;
    int ans;
    for(ans =0;sz(q);ans++){
        int sz = sz(q);
        // cout << rcnt;
        for(int i=0; i < sz; i++){
            int r = q.front().o1; int c = q.front().o2; q.pop();

            for(int d=0; d <4 ;d++){
                int nr = r + "2011"[d]-'1';
                int nc = c + "1102"[d]-'1';
                if(nr <0 || nc <0 || nr>= n || nc >= m) continue;
                if(vi[nr][nc]) continue;
                if(mapp[nr][nc] == '1') {
                    
                    // mapp[nr][nc] = '0';
                    rcnt--;
                    // cout << rcnt << ' ';
                }
                vi[nr][nc] = true;
                q.push({nr,nc});
            }
        }
        if(rcnt <= 0) break;
    }
    return ans;
}



int32_t main(){ F
    cin >> n >> m;
    for(int i=0; i < n ;i++){
        for(int j=0; j <m ;j ++){
            cin >> mapp[i][j];
            if(mapp[i][j] == '1') cnt++;
            else coords.push_back({i,j});
        }
    }
    int ans=1<<30;
    // cout << coords.size() << ' ' << cnt;
    for(int i=0; i < sz(coords); i++){
        for(int j=i+1; j < sz(coords); j++){
            ans = min(ans,bfs(i,j));
        }
    }
    cout << ans + 1;
}