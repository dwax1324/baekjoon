#include <bits/stdc++.h>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int a,b,x,y;
    cin >> a >> b >> x >> y;

    int cs1= abs(b-a);
    int cs2= abs(a-x) + abs(y-b);
    int cs3 = abs(a-y) + abs(b-x);
    cout << min({cs1,cs2,cs3});


}