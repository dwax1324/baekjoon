#include <bits/stdc++.h>

using namespace std;

struct info{
    int a,b,c;
};


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);


    int n;
    cin >> n;
    int ans=0;
    vector<info> v;
    for(int i=0; i < n; i++){
            info ff;
            cin >> ff.a >> ff.b >> ff.c;
            v.push_back(ff);
    }

    for(int j=0; j <3; j++){
        int arr[4],cnt=0;
        memset(arr,0,sizeof(arr));
        arr[j+1] =1;
        for(int i=0; i < n; i++){
            int a = v[i].a , b= v[i].b , c=v[i].c;
            swap(arr[a],arr[b]);
            if(arr[c]) cnt++;
        }
        ans = max(ans,cnt);
    }
    cout << ans;
}

