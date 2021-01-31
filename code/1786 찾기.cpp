#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define debug freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define o1 first
#define o2 second
#define endl '\n'
typedef pair<int,int> pi;
typedef tuple<int,int,int> tii;
// #define int int64_t
/*
    2021.01.28 Fri
    comment:  KMP algorithm
*/
const int MAX = 1000001;

int32_t main(){
    int N,M;
    string W,S;
    getline(cin,S);
    getline(cin,W);
    N = S.size();
    M = W.size();

    int fail[MAX]={0};
    for(int i=1,j=0; i< M; i++){
        while(j > 0 && W[i] != W[j]) j= fail[j-1];
        if(W[i] == W[j]) fail[i] = ++j;
    }


    // S,W의 일치하는 지점으 result에 모음
    vector<int> result;
    for(int i=0, j=0; i < N; i++){
        // 현재 글자가 불일치하면 fail값을 계속 따라감
        while(j > 0 && S[i] != W[j]) j = fail[j-1];
        // 현재 글자가 일치
        if(S[i] == W[j]){
            // W를 S[i:i+M-1]에서 찾음
            if(j == M-1){
                // i= 0부터 시작한다면 i-M+1. 문제 조건에 따라 1을 더함
                result.push_back(i-M+2);
                // 찾지 못한 것처럼 j를 이동시킴
                j = fail[j];
            }
            else{
                j++;
            }
        }
    }
    cout << result.size() << endl;
    for(int i : result)
        cout << i << " ";
}