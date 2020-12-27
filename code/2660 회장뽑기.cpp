#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
void misc(int &t);
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.12.27
    comment: 
    플로이드로 풀었다.
    

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/
#define int int64_t
// using long long as default, should consider TLE or RTE of it

int INF = 1<<30;
int arr[51][51];

void solve(){
    int n;
    cin >> n;
    for(int i=1; i <=n; i++){
        for(int j=1; j <= n; j++){
            if(i==j){
                arr[i][j] = 0;
            }else{
                arr[i][j] = INF;
            }
        }
    }

    for(int a,b;;){
        cin >> a>> b;
        if(a==-1 && b== -1) break;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
for(int k=1; k<= n; k++){
    for(int i=1; i<= n; i++){
        for(int j= 1; j <= n; j++){
                if(arr[i][j]  > arr[i][k] + arr[k][j]){
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    struct info{
        int a,b;
    };
    vector<info>v;
    for(int i=1; i <=n; i++){
        int MAX = 0;
        for(int j=1; j <= n; j++){
            MAX = max(arr[i][j], MAX);
        }
        v.push_back({i,MAX});
    }

    sort(all(v),[](info a, info b){
        if(a.b == b.b) return a.a < b.a;
        return a.b < b.b;
    });

    int cnt=0;
    for(auto x : v){
        if(x.b == v[0].b){
            cnt++;
        }
    }

    cout << v[0].b << " " << cnt << "\n";

    for(int i=0; i < v.size(); i++){
        if(v[i].b == v[0].b){
            cout << v[i].a << " ";
        }
    }




}


int32_t main() {
    int32_t T = 1;
    misc(T);
    // cin >> T;
    for (int i = 1; i <= T; i++) {
        // cout << "Data Set "<< i << ":\n";
        // cout << "case #" << i << ": ";
        solve();
    }
}

void misc(int32_t &T){
    fastio;
    debug;  
}