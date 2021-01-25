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
    에라토스테네스의 체 + 투포인터
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


const int MAX = 4000001;

bool vi[MAX];
vector<int> primes;

void seive(){

    for(int i=2; i <MAX; i++){
        if(vi[i]) continue;
        primes.push_back(i);
        // cout << i << " ";
        for(int j=i*2; j< MAX; j+=i){
            vi[j] = true;
        }
    }

}




void solve(){
    seive();
    int n; cin >> n;
    // for(auto x : primes)cout << x << " ";
    
    int s=0,e=0,ans=0,sum=0;
    int SIZE= primes.size();

    while(1){
        if(sum >= n){
            sum -= primes[s++];
        }else{
            if(e == SIZE) break;
            sum += primes[e++];
        }

        if(sum == n) ans++;
    }
    cout << ans;

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