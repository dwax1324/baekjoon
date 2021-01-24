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
#define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2021.01.23 Sat
    comment: 

각 소수에 대해서 K개의 소수를 계속 곱해 나가면 모든 소수의 곱을 구할 수 있는데, 여기서 중복 없이 구해서 최소 힙에 넣고 N 번째로 작은 수를 구하면 됩니다.

 

모든 소수의 곱을 구할 때 중복을 제거하는 방법은 가장 마지막에 곱해졌던 소수보다 작거나 같은 소수까지만 곱해주면 됩니다.


예를 들어

마지막에 곱해진 소수 2, 3, 5가 있을 때 각 소수에 K개의 소수인 2, 3, 5를 곱했을 때  2 * 3, 2 * 5, 3 * 5는 모두 중복입니다. 마지막에 곱해지는 수보다 큰 수를 곱하는 것은 어차피 뒤에서 한 번 더 곱해지기 때문에 더 곱해줄 필요가 없습니다.
2 x 2 | 3 x 2 | 5 x 2
2 x 3 | 3 x 3 | 5 x 3

2 x 5 | 3 x 5 | 5 x 5

출처: https://seokjin2.tistory.com/31

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


void solve(){

    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    priority_queue<int,vector<int>,greater<int>> q;
    set<int> s;
    for(int i=0; i < n; i++){
        cin >> v[i];
        q.push(v[i]);
    }

    int MAX = (1LL << 31);
    int cur;
    while(m--){
        cur = q.top();
        q.pop();

        for(int i=0; i < n; i++){
            if(v[i] * cur >= MAX) break;
            q.push(v[i]*cur);
            if(cur% v[i] == 0) break; // 중복제거
        }
    }

    cout << cur;    
    


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