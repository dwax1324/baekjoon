// date: Tue Mar 2 22:04:10 2021
// author: dwax1324
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define int int64_t
using namespace std;typedef pair<int,int> pii;typedef tuple<int,int,int> tii; typedef long long ll;


int32_t main(){ios_base::sync_with_stdio(0);cin.tie(0);
    int n; cin >> n;
    struct coords{
        int x,y,z,id;
    };
    vector<coords>v;
    for(int i=0; i < n; i++){
        int x,y,z; cin >> x >> y >> z;
        v.push_back({x,y,z,i});
    }
    struct edge{
        int u,v,w;
    };
    vector<edge> edges;

    // add edges by adjacents
    sort(all(v),[&](coords a, coords b){ return a.x < b.x; });
    for(int i=0; i < n-1; i++) edges.push_back({v[i].id,v[i+1].id,abs(v[i+1].x - v[i].x)});
    sort(all(v),[&](coords a, coords b){ return a.y < b.y; });
    for(int i=0; i < n-1; i++) edges.push_back({v[i].id,v[i+1].id,abs(v[i+1].y - v[i].y)});
    sort(all(v),[&](coords a, coords b){ return a.z < b.z; });
    for(int i=0; i < n-1; i++) edges.push_back({v[i].id,v[i+1].id,abs(v[i+1].z - v[i].z)});

    // @ union find
    struct disj{
        int pa[100001];
        disj(){
            for(int i=0; i < 100001; i++) pa[i] = i;
        }
        int find(int x){
            return pa[x] = (x== pa[x] ? x : find(pa[x]));
        }
        bool uni(int a, int b){
            a = find(a); b = find(b);
            if(a == b) return false;
            pa[b] = a;
            return true;
        }
    }disj;

    sort(all(edges),[&](edge a, edge b){
        return a.w < b.w;  
    });

    int cnt=0;
    int ans=0;
    for(int i=0; i < edges.size(); i++){
        if(disj.uni(edges[i].u,edges[i].v)){
            cnt++;
            ans += edges[i].w;
            if(cnt == n-1)break;
        }
    }
    cout << ans;



}