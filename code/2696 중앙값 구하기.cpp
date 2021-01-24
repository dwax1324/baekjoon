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
    자료구조문제 

    기본적으로 mxq에는 중앙값 + 중앙값 미만의 값, mnq에는 중앙값 이상의 값을 넣어 유지시켜줍니다.
    만약 mxq와 mnq가 모두 비었다면, mxq에 수를 넣어줍니다. (초기상태)
    mxq.size() > mnq.size() 인 경우,
    들어온 수가 현재 중앙값(mxq.top())보다 작다면 중앙값을 교체해주어야 합니다. mxq.top을 mnq에 넣어주고 현재 값을 mxq에 넣어줍니다.
    들어온 수가 현재 중앙값(mxq.top())보다 크거나 같다면 mnq에 넣어줍니다.
    mxq.size() == mnq.size()인 경우,
    들어온 수가 현재 중앙값(mxq.top())보다 크다면 중앙값을 교체해주어야합니다. 먼저 mnq에 넣은 후 mnq.top(중앙값보다 큰 값들 중 최솟값)을 mxq에 다시 넣어줌으로서 중앙값 업데이트를 할 수 있습니다.
    그 이외의 경우는 그냥 mxq에 넣어줍니다.

    출처 : https://velog.io/@ss-won/PS-%EB%B0%B1%EC%A4%80-2696-%EC%A4%91%EC%95%99%EA%B0%92-%EA%B5%AC%ED%95%98%EA%B8%B0-%EB%AC%B8%EC%A0%9C-%ED%92%80%EC%9D%B4

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


void solve(){

    int T; cin >> T; while(T--){

        int n; cin >>n;
        priority_queue<int, vector<int>, less<int>> maxq;
        priority_queue<int, vector<int>, greater<int>> minq;
        
        cout << (n+1)/2 << '\n';

        int temp =0;
        for(int i=0; i< n; i++){
            int a; cin >> a;

            if(maxq.size() == 0 && minq.size() == 0){
                maxq.push(a);
            }else if(maxq.size() > minq.size()){
                if(maxq.top() > a){
                    maxq.push(a);
                    minq.push(maxq.top()); maxq.pop();
                }else{
                    minq.push(a);
                }
            }else if(maxq.size() == minq.size()){
                if(maxq.top() < a){
                    minq.push(a);
                    maxq.push(minq.top()); minq.pop();
                }else{
                    maxq.push(a);
                }
            }

            if(i%2 == 0){
                cout << maxq.top() << ' ';
                temp++;
                if(temp %10 == 0) cout << '\n';
            }
    
        }
        cout << '\n';


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