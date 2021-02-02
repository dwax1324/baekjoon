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
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
// #define int int64_t
/*---------------------/
            2021.02.01 Mon
comment:
    구현
    
/----------------------*/

int dfs2(int a, int b){
    if(a <= 0 && b<=0){
        return 0;
    }
    int ret=1<<30;
    ret = min(ret,dfs2(a-9,b-3)+1);
    ret = min(ret,dfs2(a-3,b-9)+1);
    return ret;
}


int dfs3(int a, int b , int c,vector<int> v){
    if(a<=0 && b <=0 && c<=0){
        return 0;
    }

    int ret = 1<<30;
    do{
        ret = min(ret,dfs3(a-v[0],b-v[1],c-v[2],v)+1);
    }while(next_permutation(all(v)));
    return ret;
}


int32_t main(){ F
    int n,a,b,c;
    cin >> n;
    if(n ==1 ) {
        cin >> a;
        cout << (a%9 ? a/9 +1 : a/9 );
    }else if(n==2){
        cin >> a >> b;
        cout << dfs2(a,b);
    }else{
        cin >> a >> b >> c;
        cout << dfs3(a,b,c,{1,3,9});
    }

}