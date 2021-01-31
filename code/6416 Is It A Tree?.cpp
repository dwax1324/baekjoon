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
/*
    2021.01.30 Fri 
    comment:
    자료구조. 트리
    입력이 까다롭다.
*/

map<int,int> indegree;
set<int> nodes;
int32_t main(){
    fastio;
    for(int t=1; ; t++){
        int u,v; cin >> u >> v; 
        if(u==-1 && v==-1) break;
        indegree={};
        nodes={};edges={};

        while(1){
            if(!u && !v) break;
            if(indegree[v] == 0 ) indegree[v]=1;
            else indegree[v] += 1;
            nodes.insert(u);
            nodes.insert(v);
            cin >> u >> v;
            if(!u && !v) break;
        }
        int cond1=0,cond2=0;
        for(auto node : nodes){
            if(indegree[node] == 0 ) cond1++;
            if(indegree[node] == 1 ) cond2++;
        }
        cout << "Case " << t << ((nodes.size() == 0 || cond1 == 1 &&  cond2 == nodes.size()-1) ? " is a tree." : " is not a tree.") << endl;
    }
}