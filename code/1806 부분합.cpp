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
    2021.01.25 Mon
    comment: 
    우리의 투 포인터 알고리즘 자체가 현재 부분합이 S 이상이면 가능한 한 구간 크기를 작게 만드려고 애쓰기 때문에 이 문제가 투 포인터로 풀립니다.


⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int arr[100001];
int N, S;

int twoPointer(){
    int s=0,e=0,sum=0,ret=1<<30;

    while(1){
        if(sum >= S){
            ret = min(ret, e-s);
            sum -= arr[s++];
        }else{
            if(e == N) break;
            sum += arr[e++];
        }
    }
    if(ret == 1<<30) ret =0;
    return ret;

}


void solve(){
    cin >> N >> S;

    for(int i=0; i < N; i++){
        cin >> arr[i];
    }

    cout << twoPointer();
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