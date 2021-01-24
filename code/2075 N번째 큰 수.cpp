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
    2021.01.22 Fri
    comment: 
    메모리제한이 12mb이기 때문에 
    1500^2의 자료를 다 저장하지 못한다.

    최소힙을 이용해서 n개만큼만 큐에 담아놓는다.
    n개를 초과하면 팝해준다.

    최소힙이고 n번째 큰수를 원하기 때문에 top이 정답이다.

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


void solve(){
    int n; cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0; i < n; i++){

        for(int j=0; j < n; j++){
            int a; cin >> a;
            pq.push(a);
            if(pq.size() > n) pq.pop();
        }
    }


    cout << pq.top();



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