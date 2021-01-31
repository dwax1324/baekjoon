#include <bits/stdc++.h>
using namespace std;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define int int64_t
/*---------------------/
            2021.01.30 Sat
comment:
    히스토 스택
/----------------------*/

vector<int> h;

int histo(){
    stack<int> stk;
    h.push_back(0);
    int ret =0;
    for(int i=0; i < h.size(); i++){
        while(stk.size() && h[stk.top()] >= h[i]){
            int j = stk.top(); stk.pop();
            int width = -1;
            if(stk.size()==0)
                width = i;
            else
                width = (i-stk.top()-1);
            ret = max(ret,h[j]*width);
        }
        stk.push(i);
    }
    return ret;
}


int32_t main(){ F

    h={};
    int n; cin >> n;
    for(int i=0; i < n; i++){
        int a; cin >> a;h.push_back(a);
    }
    cout << histo() << endl;

}