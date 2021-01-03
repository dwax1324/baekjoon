#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.01.03 Sun
    comment: 
    그리디 강의실 갯수 배정

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
struct Time{
    int start,end;
};



void solve(){
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<Time> schedule(n);
    for(int i=0; i < n; i++){
        cin >> schedule[i].start >> schedule[i].end;
    }
    sort(all(schedule),[](Time a, Time b){
        return a.start < b.start;
    });

    pq.push(schedule[0].end);

    for(int i=1;i < n; i++){
        if(pq.top() <= schedule[i].start){
            pq.pop();
            pq.push(schedule[i].end);
        }else{
            pq.push(schedule[i].end);
        }
    }

    cout << pq.size();

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