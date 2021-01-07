#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
// #define int int64_t
/* ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾
    2020.01.07 Thu
    comment: 
    bfs+해싱

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

vector<vector<int>> move(vector<int>&v){
    int i;
    vector<vector<int>> ret;
    for(i=0  ; i< v.size(); i++){
        if(v[i] == 0){
            break;
        }
    }
    vector<int> temp = v;
    if(i== 0){
        swap(temp[0],temp[1]);
        ret.push_back(temp);
        temp =v;
        swap(temp[0],temp[3]);
        ret.push_back(temp);
    }else if(i ==1){
        swap(temp[1],temp[0]);
        ret.push_back(temp);
        temp =v;
        swap(temp[1],temp[2]);
        ret.push_back(temp);
        temp =v;
        swap(temp[1],temp[4]);
        ret.push_back(temp);
    }else if(i ==2 ){
        swap(temp[2],temp[1]);
        ret.push_back(temp);
        temp =v;
        swap(temp[2],temp[5]);
        ret.push_back(temp);
    }else if(i ==3 ){
        swap(temp[3],temp[0]);
        ret.push_back(temp);
        temp =v;
        swap(temp[3],temp[4]);
        ret.push_back(temp);
        temp =v;
        swap(temp[3],temp[6]);
        ret.push_back(temp);
    }else if(i ==4 ){
        swap(temp[4],temp[1]);
        ret.push_back(temp);
        temp =v;
        swap(temp[4],temp[3]);
        ret.push_back(temp);
        temp =v;
        swap(temp[4],temp[5]);
        ret.push_back(temp);
        temp =v;
        swap(temp[4],temp[7]);
        ret.push_back(temp);
    }else if(i ==5 ){
        swap(temp[5],temp[2]);
        ret.push_back(temp);
        temp =v;
        swap(temp[5],temp[4]);
        ret.push_back(temp);
        temp =v;
        swap(temp[5],temp[8]);
        ret.push_back(temp);
    }else if(i ==6 ){
        swap(temp[6],temp[3]);
        ret.push_back(temp);
        temp =v;
        swap(temp[6],temp[7]);
        ret.push_back(temp);
    }else if(i ==7 ){
        swap(temp[7],temp[4]);
        ret.push_back(temp);
        temp =v;
        swap(temp[7],temp[6]);
        ret.push_back(temp);
        temp =v;
        swap(temp[7],temp[8]);
        ret.push_back(temp);
    }else if(i ==8 ){
        swap(temp[8],temp[5]);
        ret.push_back(temp);
        temp =v;
        swap(temp[8],temp[7]);
        ret.push_back(temp);
        temp =v;
    }

    return ret;
}


void solve(){
    map<vector<int>, int> vi;


    vector<int> start;
    vector<int> goal = {1,2,3,4,5,6,7,8,0};
    for(int i=0; i < 9; i++){
        int a; cin >> a;
        start.push_back(a);
    }

    vi[start] =1;
    queue<vector<int>> q;
    q.push(start);

    int ans=0;
    bool success = false;
    for(;q.size();ans++){
        int qSize = q.size();
        if(vi[goal]==1) {
            success = true;
            break;
        }
        for(int i=0;  i < qSize; i++){
            vector<int> cur = q.front(); q.pop();

            vector<vector<int>> ncur = move(cur);
            for(auto x : ncur){
                if(vi[x] == 1) continue;
                q.push(x);
                vi[x] = 1;
            }
        }
    }

    if(!success) cout << -1;
    else cout << ans;

    

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