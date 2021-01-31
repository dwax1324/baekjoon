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
// #define int int64_t
/*---------------------/
            2021.01.30 Fri
comment:
    Suffix Array, LCP
/----------------------*/

const int MAX = 1<<19;
char S[MAX];
int N, d, sa[MAX], pos[MAX],lcp[MAX];

bool cmp(int i, int j){
    if(pos[i] != pos[j]) return pos[i] < pos[j];
    i += d;
    j += d;
    return (i < N && j < N) ? (pos[i] < pos[j]) : (i > j);
}

void constructSA(){
    N = strlen(S);
    for(int i=0; i < N; i++){
        sa[i] = i;
        pos[i] = S[i];
    }

    for(d =1; ;d*=2){
        sort(sa, sa+N, cmp);

        int temp[MAX] = {0};

        for(int i=0; i < N-1; i++)
            temp[i+1] = temp[i] + cmp(sa[i],sa[i+1]);
        for(int i=0; i < N; i++)
            pos[sa[i]] = temp[i];       

        if(temp[N-1] == N-1) break;
    }
}

void constructLCP(){
    for(int i=0,k=0; i < N; i++,k=max(k-1,0)){
        if(pos[i] == N-1) continue;
        for(int j=sa[pos[i]+1]; S[i+k] == S[j+k]; k++);
        lcp[pos[i]] = k;
    }

}



int32_t main(){ F
    cin >> S;
    constructSA();
    constructLCP();

    for(int i=0; i < N; i++)
        cout << sa[i] +1 << ' ';
    cout << "\nx" << ' ';
    for(int i=0; i < N-1; i++){
        cout << lcp[i] << ' ';
    }
}