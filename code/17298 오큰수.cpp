#include <bits/stdc++.h>
using namespace std;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
#define tii tuple<int,int,int>
#define pii pair<int,int>
// #define int int64_t
/*---------------------/
            2021.02.01 Mon
comment:
    자료구조 스택
    
/----------------------*/

int arr[1000001];

int32_t main(){ F
    int n; cin >> n;
    stack<pii>stk;
    arr[n-1] =-1;
    for(int i=0; i < n; i++){
        int a; cin >> a;
        pii b = {a,i};
        if(i==0 || stk.size() == 0){
            stk.push(b);
        }else{
            if(stk.top().o1 < a){
                while(1){
                    if(stk.size()==0)break;
                    if(stk.top().o1 < a){
                        arr[stk.top().o2] = a;
                        stk.pop();
                    }else break;
                }

            }
            stk.push(b);
        }
    }
    // cout << stk.size();
    while(stk.size()){
        arr[stk.top().o2] = -1;
        stk.pop();
    }

    // while(stk.size()){
    //     pii curr = stk.top(); stk.pop();
    //     if(stk.size()==0) {
    //         // arr[curr.o1] = -1;
    //         break;
    //     }
    //     if(curr.o1 > stk.top().o1){
    //         arr[stk.top().o2] = curr.o1;
    //         stk.pop();
    //         stk.push(curr);
    //     }else{
    //         arr[stk.top().o2] = -1;
    //     }
    // }
    for(int i=0; i < n; i++){
        cout << arr[i] << ' ';
    }

}