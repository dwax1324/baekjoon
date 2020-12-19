#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pic pair<int, char>
#define pci pair<int, char>
#define pipii pair<int, pii>
#define pll pair<long, long>
#define tiii tuple<int, int, int>
#define sz(x) (int)(x).size()
#define pb push_back
#define acc accumulate
#define ff(a,i ,b) for(int i =(a); i <= (b); ++i)
#define rff(a,i, b) for(int i= (a) ; i>=(b); --i)
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define error(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
        cout << '\n';                            \
    }
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a << ' ';
    err(++it, args...);
}
void misc(int &t);
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    구현
    타자와 선수를 잘 구분해야한다
⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/


int n,ans;
int arr[51][10];
int order[10];
bool selected[10];

void play(){
    int idx = 1, score=0;

    for(int inning =1; inning <= n; inning++){
        bool field[3] = {0,0,0};
        int out =0;
        while(1){
            if(arr[inning][order[idx]] == 0){
                out ++;
            }
            else if(arr[inning][order[idx]] == 1){
                if(field[2]){ 
                    score++; 
                    field[2] = false;
                }
                for(int i=1; i>= 0;i--){
                    if(field[i]){
                        field[i+1] = true;
                        field[i] = false;
                    }
                }
                field[0] = true;
            }else if(arr[inning][order[idx]] ==2){
                for(int i=1; i<3; i++){
                    if(field[i]){
                        score++; field[i] = false;
                    }
                }
                if(field[0]){
                    field[2] = true; field[0]=false;
                }
                field[1] = true;
            }else if(arr[inning][order[idx]] == 3){
                for(int i=0; i <3; i++){
                    if(field[i]){
                        score++; field[i] = false;
                    }
                }
                field[2] = true;
            }else{
                for(int i=0; i <3 ;i++){
                    if(field[i]){
                        score++;field[i] = false;
                    }
                }
                score++;
            }
            idx = (idx+1);
            if(idx==10) idx=1;
            if(out==3) break;
        }

    }
    if(ans < score) ans=  score;
}


void perm(int cur){
    if(cur == 10){
        play();
        return;
    }
    if(cur == 4) cur++;

    for(int i=1; i<= 9; i++){
        if(selected[i]) continue;
        selected[i] = true;
        order[cur] = i;
        perm(cur+1);
        selected[i] =false;
    }

}

void solve(){
    cin >> n;
    for(int i=1; i <= n ;i++){
        for(int j=1; j <= 9 ;j ++){
            cin >> arr[i][j];
        }
    }
    
    selected[1] = true; order[4] = true;
    perm(1);
    cout << ans;
}


auto main() -> int {
    int t = 1;
	misc(t);
    for (int i = 1; i <= t; i++) {
        // cout << "case #" << i << ": ";
        solve();
    }
}

void misc(int &t){
    fastio;
	debug;  
	// cin >> t;
}