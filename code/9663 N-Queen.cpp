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
#define tii tuple<int,int,int>
#define pii pair<int,int>
// #define int int64_t
/*---------------------/
            2021.02.01 Mon
comment:
    백트래킹
    
/----------------------*/


int curr[16]; // 현재칸을 나타내는 배열
int n; // 맥시멈길이

bool ok(int row){ // 제한을 확인하는 함수
    for(int i=0; i < row; i++){  // 현재까지 내려온 칸들과 비교
        // 만약 현재칸의 위치와 이전칸의 위치가 같거나
        // 대각선의 위치가 같다면 false를 반환
        if(curr[row] == curr[i] || abs(curr[row]-curr[i]) == (row-i)) return false;
    }
    return true;
}


int solve(int row){
    if(row == n){ // 범위초과시 
        return 1; // 찾았음!
    }
    int ret =0;

    for(int i=0; i < n; i++){
        curr[row] = i; // 현재층의 퀸의 위치를 저장
        if(ok(row)){ // 만약 이 자리가 괜찮다면
            ret += solve(row+1); // 다음층으로 넘어감
        }
    }
    return ret;
}

int32_t main(){ F
    cin >> n;
    cout << solve(0);
}