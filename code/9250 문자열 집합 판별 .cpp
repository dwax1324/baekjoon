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
    Aho-Corasick
    
/----------------------*/


struct Trie{
    Trie *go[26];
    Trie *fail;
    bool output;

    Trie(){
        fill(go, go+26, nullptr);
        output = false;
    }
    // ~Trie(){
    //     for(int i=0; i < 26;i ++){
    //         if(go[i]) delete go[i];
    //     }
    // }
    void insert(const char* key){
        if(*key == '\0'){
            output = true;
            return;
        }
        int next = *key - 'a';
        if(!go[next]){
            go[next] = new Trie;
        }
        go[next]-> insert(key+1);

    }

};

int32_t main(){ F
    int N,M;
    char str[10001];
    Trie* root = new Trie;
    cin >> N;
    for(int i=0; i < N; i++){
        cin >> str; // scanf("%s",str);
        root ->insert(str);
    }

    queue<Trie*> Q;
    root->fail = root;
    Q.push(root);

    while(Q.size()){
        Trie *current = Q.front();
        Q.pop();

        for(int i=0; i < 26; i++){
            Trie *next = current->go[i];
            if(!next) continue;

            if(current == root) next ->fail = root;
            else{
                Trie *dest = current->fail;
                while(dest != root && !dest->go[i])
                    dest = dest->fail;
                if(dest->go[i]) dest = dest->go[i];
                next->fail = dest;
            }
            if(next->fail->output) next->output = true;

            Q.push(next);
        }
    }

    cin >> M;
    for(int i=0; i < M; i++){
        cin >> str;
        Trie* current = root;
        bool result = false;
        for(int c= 0; str[c] ; c++){
            int next = str[c] -'a';
            while(current != root && !current ->go[next])
                current = current ->fail;
            if(current-> go[next])
                current= current->go[next];
            if(current->output){
                result = true;
                break;
            }
        }
        cout << (result ? "YES" : "NO") << endl;
    }
    // delete(root);

}