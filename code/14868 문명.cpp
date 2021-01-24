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
    BFS + UNION FIND
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

// 방향
const int roff[4] = {-1,1,0,0};
const int coff[4] = {0,0,1,-1};


// 유파 구조체
struct UnionFind{

    // 부모배열
    int p[100001];
    // 생성자: 부모배열 -1로 초기화
    UnionFind(){ fill(p,p+100000, -1);}

    // 파인드
    int f(int a){
        if(p[a] <0 ) return a;
        return p[a] = f(p[a]);
    }
    // 유니온
    // p배열이 루트면 음수로 집합의 크기를 저장한다.
    bool u(int a, int b){
        a = f(a);
        b = f(b);
        if(a == b) return false;
        if(p[a] <  p[b]){
            p[a] += p[b];
            p[b] = a;
        }
        else{
            p[b] += p[a];
            p[a] = b;
        }
        return true;
    }
};

// 맵배열
int map_[2001][2001];

void solve(){
    int N,K;
    cin >> N>> K;

    // -1로 초기화
    memset(map_,-1,sizeof(map_));
    queue<int> q;
    UnionFind UF;

    for(int i=0; i < K; i++){
        int r,c; cin >> r >> c; r-- ; c --;
        // map[r][c]를  0.. k-1 번째로 설정
        map_[r][c] = i;

        // 큐에 좌표정보를 넣는다.
        q.push(r*2000 + c);

        // 초기문명이 인접해있으면 유니온해준다.
        for(int d=0; d<4 ;d++){
            int nr = r+ roff[d], nc = c+coff[d];
            if (nr <0 || nc <0 || nr>= N || nc >=N || map_[nr][nc] <0 ) continue;
            UF.u(map_[r][c] , map_[nr][nc]);
        }
    }

    int res =0;

    // bfs
    // 유니온파인드의 집합의 크기가 K가 될떄까지
    for(; UF.p[UF.f(0)] != -K; res++){
        int qs = q.size();
        for(int i=0; i < qs; i++){
            int r = q.front()/2000, c= q.front()%2000; q.pop();
            
            // 4방향탐색
            for(int d= 0; d< 4; d++){
                int nr = r+ roff[d] , nc = c+ coff[d];
                if(nr <0 || nr >= N || nc <0 || nc>= N || map_[nr][nc] >=0) continue;
                map_[nr][nc] = map_[r][c];
                q.push(nr*2000 + nc);
                // 새로 나아간 자리에서 또 4방향 유니온파인드해준다.
                for(int dd=0; dd < 4;  dd++){
                    int nnr = nr + roff[dd] ,nnc = nc + coff[dd];
                    if(nnr <0 || nnr >=N || nnc <0 || nnc >=N || map_[nnr][nnc] <0 ) continue;
                    UF.u(map_[nnr][nnc], map_[r][c]);
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