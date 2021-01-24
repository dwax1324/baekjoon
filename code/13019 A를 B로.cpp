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
    그리디 ? 
    뒤에서부터 
    문자열 A와 문자열 B에 각각 포인터 하나씩 주고
    같으면 a--,b--;
    다르면 a--;
    하면서 
    같은 문자가 몇갠지 확인한다
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int go(string a, string b){
    int an = a.size();
    int bn = b.size();
    int count[27];
    if(an != bn ) return -1;
    memset(count,0,sizeof(count));

    for(int i=0; i <an; i++){
        count[a[i]-'A']++;
    }
    for(int i=0; i < bn; i++){
        count[b[i]-'A']--;
    }
    for(int i=0; i < 27; i++){
        if(count[i]) return -1;
    }

    int ret=0 , i = an-1, j = bn-1;
    while( i>=0 ){
        if(a[i] != b[j]) ret++;
        else j--;
        i--;
    }
    return ret;
}


void solve(){
    string a,b;
    cin >> a >> b;
    cout << go(a,b);
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