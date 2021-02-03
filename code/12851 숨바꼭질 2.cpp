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
            2021.02.03 Tue
comment:
    BFS
    
/----------------------*/


int vis[100001];
int dx[]={1,-1,2};
int32_t main(){ F
    int n,k; cin >> n >> k;
    
    queue<pii> q;
    q.push({n,0});
    bool first = false;
    int ans=0,distAns=0;
    for(;q.size();){
        int qs = q.size();
        for(int i=0; i < qs; i++){
            int curr = q.front().o1, dist = q.front().o2;q.pop();
            if(first && dist == distAns && curr==k ){
                // cout << distAns << ' ' << dist << '\n';
                 ans++;
            }
            if(curr == k && first == false){
                distAns = dist;
                first = true;
                ans++;
            }
            // cout << curr << ' ';
            // if(vis[curr]) continue;
            vis[curr] = true;
            for(int d=0; d < 3; d++){
                int next= curr;
                if(d==2) next *= dx[d];
                else next += dx[d];
                if(next <0 || next >100000) continue;
                if(vis[next]) continue;
                q.push({next,dist+1});
                // vis[next]=true;
            }
        }
    }
    cout << distAns << endl << ans;
    

}