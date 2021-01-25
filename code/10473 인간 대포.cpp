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
    2021.01.25 Mon
    comment: 
    기하+ 다익스트라
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

const int MAX = 105, INF = 1<<30;

pair<double,double> vertices[MAX];

typedef pair<double,int> pdi;

double pita (int u, int v){
    return sqrt(pow(vertices[u].o1 - vertices[v].o1, 2) + pow(vertices[u].o2 - vertices[v].o2,2));
}


void solve(){

    double sx,sy,ex,ey,dist[MAX];
    cin >> sx >> sy >> ex >> ey;
    int n; cin >> n;
    vertices[0] = {sx,sy};

    for(int i=1; i<= n; i++) cin >> vertices[i].o1 >> vertices[i].o2;
    vertices[n+1] = {ex,ey};

    fill(dist,dist+MAX,INF);
    dist[0] = 0;
    priority_queue<pdi, vector<pdi>,greater<pdi>> pq;
    pq.push({0,0});
    bool vi[MAX] = {0};
    bool flag = true;

    while(pq.size()){
        int curr = pq.top().o2; pq.pop();
        if(vi[curr]) continue;
        vi[curr]= true;

        for(int v=1; v<= n+1; v++){
            double t1= pita(curr,v) /5.0;
            double t2 = 2.0+ abs(pita(curr,v) -50) /5.0;
            double t = flag ? t1 : min(t1,t2);

            if(dist[v]  > dist[curr] + t){
                dist[v] = dist[curr] + t;
                pq.push({dist[v], v});
            }

        }
        flag = false;
    }
    cout << setprecision(10) << dist[n+1] << '\n';


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