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
            2021.02.02 Tue
comment:
    슬라이딩윈도우
    
/----------------------*/


int cnt[3000001];
int32_t main(){ F
    int n,d,k,c;
    cin >> n >> d >> k >> c;
    vector<int>v(n);
    for(int i=0; i < n; i++){
        cin >> v[i];
    }
    //// 여기까지입력 ..OK

    int s=0,e=0; // 투포인터
    int ans=0;   // temp변수임 사실
    int ret=-1;  // 결과값
    cnt[c] = 1<<30; ans++; // 쿠폰은 무한정있다고 치자. 하나 있으니  ans에 1추가
    for(e=0; e < k; e++){
        if(cnt[v[e]] ==0) { // 만약 처음으로 먹는 초밥이면
            ret=max(ret,++ans);  // 정답에 1추가
        }
        cnt[v[e]]++;
    }

    while(1){
        if(s == n ) break;  // start포인터가 끝에 다다랐으면.. 끝
        if(e == n ) e %= n; // end포인터가 끝에 다다랐으면 처음으로 돌아간다
        if(--cnt[v[s]] <= 0 ){  // 만약 v[s]의 가짓수에서 초밥 하나를 뻇을 그 가짓수가 없어진다면
            cnt[v[s]] =0;
             ret= max(ret,--ans); // ans에서 하나를 뺀다.
        }
        if(cnt[v[e]]++ ==0) ret=max(ret,++ans); // 만약 처음먹는거면 1을 추가해준다.
        s++;e++;        // start와 end를 동시에 올려준다(슬라이딩 윈도우)
    }
    cout << ret;



}