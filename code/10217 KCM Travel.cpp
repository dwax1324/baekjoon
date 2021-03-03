// date: Tue Mar 2 19:46:05 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
//#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;



int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
int tt; cin >> tt; while(tt--){
    int N,M,K; cin >> N>> M>> K;

    vector<tii> adj[101];
    for(int i=0; i < K; i++){
        int u,v,w,t; cin >> u >> v >> w >> t; u--;v--;
        adj[u].push_back({t,v,w});
    }
    
    const int INF = 1<<30;
    // F dijkstra
    auto dijk = [&](int s, int e){
        int dp[101][10001]; // dp[i][j] : 1번 도시에서 i번 도시까지 비용 j를 써서 갈 때 최소 시간
        for(int i=0; i < 101; i++)
            fill(dp[i],dp[i]+10001,INF);
        priority_queue<tii,vector<tii>,greater<tii>> pq;
        pq.push({0,0,0});
        dp[0][0] = 0;
        while(pq.size()){
            int currTime,currCost,curr;
            tie(currTime,curr,currCost) = pq.top();pq.pop();
            if(curr == e) return currTime;
            if(dp[curr][currCost] < currTime){ // 이미 city에 cost를 써서 더 빨리 도달한 경우가 있을 경우
                continue;
            }
            for(auto p : adj[curr]){
                int nextTime,nextCost,next;
                tie(nextTime,next,nextCost) = p;
                if(currCost + nextCost > M) continue;
                if(dp[next][currCost+nextCost] > currTime + nextTime){
                    dp[next][currCost+nextCost] = currTime+nextTime;
                    pq.push({ nextTime + currTime , next , currCost+nextCost});
                }
            }
        }
        return -1;
    };

    int ans = dijk(0,N-1);
    if(ans == -1) cout << "Poor KCM\n";
    else cout << ans << '\n';
}
}