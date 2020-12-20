#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int n, a;
    cin >> n >> a;

    if(n>5){
        cout << "Love is open door";
    }else{
        for(int i=0; i < n; i++){
            if(i==0) continue;
            if(a==0){
                if(i%2==0){
                    cout << 0 << '\n';
                }else{
                    cout << 1 << '\n';
                }
            }else{
                if(i%2==0){
                    cout << 1 << '\n';
                }else{
                    cout << 0 << '\n';
                }
            }
        }
        }
}

