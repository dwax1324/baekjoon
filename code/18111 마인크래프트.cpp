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
#define int int64_t
/*---------------------/
            2021.02.04 Thu
comment:
    ±¸Çö,¿ÏÅ½
    
/----------------------*/

const int INF = 1ll<<62;
int M,N,B;
int cost[257]; // cost = time
int mapp[501][501]; 

int getCost(int x){
    int ret=0;
    int inven = B;
    for(int i=0; i < M; i++){
        for(int j=0; j < N; j++){
            if(mapp[i][j] > x){
                inven += mapp[i][j] -x;
                ret += 2*(mapp[i][j]-x);
            }
        }
    }

    for(int i=0; i < M; i++){
        for(int j=0; j < N; j++){
            if(mapp[i][j] < x){
                inven -= x-mapp[i][j];
                ret += 1*(x-mapp[i][j]);
                if(inven < 0) return INF;
            }
        }
    }
    return ret;
}



int32_t main(){ F
    cin >> M >> N >> B;
    for(int i=0 ;i < M; i++){
        for(int j=0; j < N; j++){
            cin >> mapp[i][j];
        }
    }
    int MIN = INF;
    for(int i=0; i < 257; i++){
        cost[i] = getCost(i);
        MIN= min(cost[i],MIN);
    }

    for(int i=256; i >=0; i--){
        if(cost[i] == MIN) {
            cout << cost[i] << ' ' << i;
            exit(0);
        }
    }

}