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
    2021.01.23 Sun
    comment: 
    스파스테이블
    
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int arr[200001][19],N,M,K;

// 수의 자릿수를 반환한다.
int digit(int n){

    int ret =0;
    while(n%2 == 0){
        n /=2;
        ret++;
    }
    return ret;
}


void solve(){
    cin >> N ;
    // 전처리 SPT을 만든다
    for(int i=1; i<= N; i++)
        cin >> arr[i][0];
    for(int j=1; j< 19; j++)
        for(int i=1; i<=N; i++)
            arr[i][j] = arr[arr[i][j-1]][j-1];
    cin >> K;

    for(int i=0; i < K; i++){
        int a,b; cin >> a >> b;
        while(a){
            b = arr[b][digit(a)];
            a &= (a-1);
        }
        cout << b << '\n';
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