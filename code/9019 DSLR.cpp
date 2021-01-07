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
    bfs

⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾ ⁽⁽◝( ˙ ꒳ ˙ )◜⁾⁾*/

struct info{
    char instruct;
    int prev;
};


bool vi[10001];
info trace[10001];

int getL(int &x){
    string s = to_string(x);
    if(s.size() !=4){
        while(s.size()!=4){
        s.insert(s.begin(),'0');
        }
    }
    string s2 = s;

    for(int i=0; i < s.size()-1; i++){
        s[i] = s2[i+1];
    }

    s[s.size()-1] = s2[0];
    return stoi(s);
}

int getR(int &x){
    string s = to_string(x);
    if(s.size() !=4){
        while(s.size()!=4){
        s.insert(s.begin(),'0');
        }
    }

    string s2 = s;

    for(int i=1; i < s.size(); i++){
        s[i] = s2[i-1];
    }

    s[0] = s2[s2.size()-1];
    return stoi(s);
}


void solve(){


    int T; cin >> T; while(T--){
        memset(vi,0,sizeof(vi));
        memset(trace,0,sizeof(trace));

        int A, B;
        cin >> A >> B;
        
        queue<int>q;

        q.push(A);
        vi[A] = true;


        bool success= false;
        for(;q.size();){
            int qSize = q.size();
            if(vi[B]) break;
            for(int i=0; i < qSize; i++){
                int cur = q.front(); q.pop();

                int ncur;

                ncur = (cur *2) % 10000;

                if(!vi[ncur]){
                    vi[ncur] = true; q.push(ncur);
                    trace[ncur].instruct = 'D';
                    trace[ncur].prev =cur;
                }

                ncur = cur -1;
                if(ncur < 0) ncur = 9999;

                if(!vi[ncur]){
                    vi[ncur] = true; q.push(ncur);
                    trace[ncur].instruct = 'S';
                    trace[ncur].prev =cur;
                }

                ncur = getL(cur);

                if(!vi[ncur]){
                    vi[ncur] = true; q.push(ncur);
                    trace[ncur].instruct = 'L';
                    trace[ncur].prev =cur;
                }

                ncur = getR(cur);

                if(!vi[ncur]){
                    vi[ncur] = true; q.push(ncur);
                    trace[ncur].instruct = 'R';
                    trace[ncur].prev =cur;
                }
            }
        }
        int cur = B;
        stack<char> ss;
        while(cur != A){
            ss.push(trace[cur].instruct);
            cur = trace[cur].prev;
        }

        while(ss.size()){
            cout << ss.top();
            ss.pop();
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