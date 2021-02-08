// date: Sun Feb 7 19:18:59 2021
// author: dwax1324
#include <bits/stdc++.h>
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii;
#define F ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
// #define int int64_t

// 중복순열 + 식평가문제
// 굉장히 돌아돌아 풀었다. 2시간걸림

// 문자열로 처리해서 그런듯..
// 일단 중복순열로 가능한 부호들을 쫙 뽑은다음에
// 숫자와 부호들을 하나씩 매핑하면서 만약 공백이면 
// 숫자들을 이어붙힘.
// 그리고 식을 평가해야하는데 파이썬에선 eval()쓰면 끝나는데
// 어떻게하지하다가 후위표기식밖에 생각이 안나서 그냥
// 스택두개썻는데
// 또 스택에 넣으면 순서가 반대로되서
// 큐에넣은담에 또 스택에다넣음
// 요새왤케 머리가 안돌아가지

int n; 
char arr[10];
char selected[10];
int cnt=0;
vector<string> ans;
void eval(){

    string s="";
    for(int i=0; i < n; i++){
        s+= to_string(i+1);
        if(i!=n-1) {
            if(selected[i] == ' ') continue;
            s+= selected[i];
        }
    }
    stack<int> q1,q2;
    string buff="";
    for(int i=0; i < sz(s); i++){
        if(s[i]<= '9' && s[i] >='0') buff+=s[i];
        else{
            if(s[i] == '+')
                q2.push(1);
            else 
                q2.push(2);
            q1.push(stoi(buff));
            buff="";
        }
    }
    if(buff != "") q1.push(stoi(buff));
    if(q2.size() == 0) return;
    stack<int> stk1,stk2;

    while(q1.size()){
        stk1.push(q1.top()); q1.pop();
    }
    while(q2.size()){
        stk2.push(q2.top()); q2.pop();
    }

    while(stk2.size()){
        int a = stk1.top(); stk1.pop();
        int b = stk1.top(); stk1.pop();
        if(stk2.top() == 1)
            stk1.push(a+b);
        else
            stk1.push(a-b);
        stk2.pop();
    }
    // cout << stk1.size();
    int curr = stk1.top();
    // cout << curr;
    // cout << q1.size() << ' '<< q1.front() << endl;
    if(curr == 0){
        string z = "";
        for(int i=0; i < n; i++){
            z += to_string(i+1);
            if(i!= n-1) z += selected[i];
        }
        ans.push_back(z);
    }
}

void dfs(int a){
    if(a==n-1){
        // for(int i=0; i< n; i++){
        //     cout << selected[i] << ' ';
        // }
        eval();
        return;
    }

    for(int i=0; i< 3;i++){
        selected[a] = arr[i];
        dfs(a+1);
    }
}

void solve(){
    arr[0] ='+';
    arr[1] = '-';
    arr[2] = ' ';
    ans={};
    cin >> n;
    dfs(0);
    sort(all(ans));
    for(auto x : ans){
        cout << x << endl;
    }
}


int32_t main(){ F int t=1;
cin >> t;
while(t--) {
    solve();
    if(t>=1) cout << endl;   
};}