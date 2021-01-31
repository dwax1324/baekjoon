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
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
// #define int int64_t
/*---------------------/
            2021.01.30 Fri
comment:
    자료구조, 트라이    
/----------------------*/

const int alpha = 26, MAX = 100000;
bool initial;
int ans,n;
char arr[MAX][81];

struct Trie{
    Trie* pan[alpha];
    bool end;
    int cnt;
    Trie() {
        for(int i=0; i < alpha; i++)
            pan[i] = nullptr;
        end = false;
        cnt=0;
    }
    ~Trie() {
        for(int i=0; i < alpha; i++){
            if(pan[i] != nullptr)
                delete pan[i];
        }
    }

    void insert(char* str){
        if(*str == '\0'){
            end = true;
            return;
        }

        int cur = *str -'a';
        if(pan[cur] == nullptr){
            pan[cur] = new Trie();
            cnt++;
        }
        pan[cur]->insert(str+1);
    }
    void find(char* str){
        if (*str == '\0') return;

        if (initial){
            initial = false;
            ans ++;
        }else{
            if(end) ans++;
            else if (cnt>1) ans++;
        }
        int cur = *str-'a';
        pan[cur]->find(str+1);
    }
} *root;

int32_t main(){
    fastio;
    while (cin >> n){
        root = new Trie();
        ans =0;
        for(int i=0; i < n; i++){
            cin >> arr[i];
            root->insert(arr[i]);
        }
        for(int i=0; i < n; i++){
            initial = true;
            root-> find(arr[i]);
        }
        cout << fixed << setprecision(2) << (double)ans/ (double) n << endl;
        delete root;
    }
}