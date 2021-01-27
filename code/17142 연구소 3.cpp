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

    시도 1. N*N을 N*M으로 적어놓고 30분동안 헤맴
    시도 2. BFS의 각 레벨에서 0인 갯수를 확인하려다
            시간초과
    시도 3. 0인 갯수를 처음에 저장해놓고 BFS로 0인 칸을
            찾을때마다 감소시켜서 0이면 값을 반환.
            시간절약, 통과
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


const int MAX= 51;

int N,M,map_[MAX][MAX],vi[MAX][MAX],cnt0=0;
// 바이러스 시작지점을 담아놓는다
vector<pii> virusStart;

// bfs
int bfs(vector<pii>&v){
    // cnt을 0의 갯수만큼 초기화시켜준다.
    int cnt=cnt0;
    // queue 에 r,c,정보를 담는다.
    queue<tuple<int,int>> q;
    // 방문배열을 초기화시킨다.
    memset(vi,0,sizeof(vi));
    for(auto x : v){
        q.push({x.o1,x.o2});
        vi[x.o1][x.o2] = true;
    }

    // 리턴값을 초기화시킨다.
    int ret=0;

    // bfs의 각 레벨마다
    for(;q.size();){
        int qs = q.size();

        // 각레벨마다 큐에담긴 정보를 뿌려준다
        for(int i=0 ; i< qs; i++){
            // r,c에 좌표정보를 담고 큐를 팝시켜준다.
            int r,c;
            tie(r,c) = q.front();
            q.pop();
            
            // 4방향마다
            for(int d= 0; d <4 ;d++){
                int nr = r + "2011"[d]-'1';
                int nc = c + "1102"[d]-'1';
                // 범위제한 튕겨낸다
                if(nr <0 || nc <0 || nr>= N || nc >= N) continue;
                // 방문했거나, 벽이면 튕겨낸다
                if(map_[nr][nc] == 1 || vi[nr][nc]) continue;
                // 만약 빈칸이면, 0의 갯수만큼 있었던 cnt를 감소시켜준다.
                if(map_[nr][nc] == 0) cnt--;
                // 큐에 걸러진 새로운 정보를 담는다.
                q.push({nr,nc});
                vi[nr][nc] = true;
            }
        }
        // 만약 0인 칸이 없으면 리턴값을 반환한다.
        ret++;
        if(cnt == 0) return ret;
    }
    // 반환되지 못했다면 매우 큰값을 반환한다.
    return 1<<30;
}

// 조합으로 가능한 M가지 바이러스 시작지점을 찾는다.
int go(int a,int n,vector<int> v){
    // M개만큼 찾았다면
    if(a == M){
        // 벡터 temp에 담고
        vector<pii> temp;
        for(auto x : v){
            temp.push_back(virusStart[x]);
        }
        // temp을 인자로 넘겨주며 bfs를 돌린다.
        return bfs(temp);
    }

    // 중복제거
    int first= v.size() ? v.back() +1 : 0;

    // 리턴값, 최솟값을 찾기위해 큰값으로 설정
    int ans=1<<30;

    // 이전위치의 다음순간부터 ~ 최대n까지 조합탐색을한다.
    for(int i= first; i< n; i++){
        // 벡터 v에 가능한 조합을 담는다.
        v.push_back(i);
        // 리턴값을 최솟값으로 설정한다.
        ans = min(ans,go(a+1,n,v));
        v.pop_back();
    }
    return ans;
}


void solve(){
    cin >> N >> M;
    for(int i=0; i < N;i ++){
        for(int j=0;j <N;j ++){
            cin >> map_[i][j];
            // 0의 갯수만큼 증가시킨다.
            if(map_[i][j] == 0) cnt0++;
            // 바이러스 시작지점에 정보를 넘겨준다.
            if(map_[i][j] == 2) virusStart.push_back({i,j});
        }
    }

    // 0인칸이 없다면 탐색할 필요가 없다.
    if(cnt0==0) {cout << 0; exit(0);}
    // 위의 함수를 실행시킨다.
    int ans = go(0,virusStart.size(),{});
    // 계속 min값만 찾앗음에도 불구하고 큰값으로 설정했던
    // 1<<30이 ans에 담기면 모든칸을 방문할 수 없기때문에 -1을 출력한다.
    // 아니면 ans를 출력한다.
    ans == (1<<30) ? cout << -1 : cout << ans;
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