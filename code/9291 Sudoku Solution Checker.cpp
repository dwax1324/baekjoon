#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
void misc(int32_t &t);
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.12.30
    comment: 
    구현

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

int arr[10][10];

bool rowError(){
    for(int i=0; i < 9; i++){
        int chk[10];
        memset(chk,0,sizeof(chk));
        for(int j=0; j < 9; j++){
            chk[arr[i][j]]++;
            if(chk[arr[i][j]]>1) return true;
        }
    }
    return false;
}

bool colError(){
    for(int i=0; i < 9; i++){
        int chk[10];
        memset(chk,0,sizeof(chk));
        for(int j=0; j < 9; j++){
            chk[arr[j][i]]++;
            if(chk[arr[j][i]]>1) return true;
        }
    }
    return false;
}


bool ttError(int y, int x){
    if(y >= 9 || x >=9) return false;



    int chk[10];
    memset(chk,0,sizeof(chk));
    for(int i=y; i< y+3; i++){
        for(int j=x; j< x+3; j++){
            // cout << arr[i][j] << " ";
            chk[arr[i][j]]++;
            if(chk[arr[i][j]] > 1) return true;
        }
    }

    
    bool ret= false;
    ret |= ttError(y,x+3);
    ret |= ttError(y+3,x);
    

    return ret;
}

void solve(){

    for(int i=0; i < 9; i++){
        for(int j=0; j < 9; j++){
            cin >> arr[i][j];
        }
    }

    if(rowError() || colError() || ttError(0,0)){
        cout << "INCORRECT\n";
    }else{
        cout << "CORRECT\n";
    }
}


int32_t main() {
    int32_t T = 1;
    misc(T);
    cin >> T;
    for (int i = 1; i <= T; i++) {
        // cout << "Data Set "<< i << ":\n";
        cout << "Case " << i << ": ";
        solve();
    }
}

void misc(int32_t &T){
    fastio;
 //   debug;  
}