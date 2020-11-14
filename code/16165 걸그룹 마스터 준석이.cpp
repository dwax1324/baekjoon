#include <bits/stdc++.h>
using namespace std;

// 단순 구현

// 맵사용
// 복잡하게 생각하지 말자

map<string, string> MAP;

int main() {
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string team;
        cin >> team;
        int members;
        cin >> members;
        for (int j = 0; j < members; j++) {
            string z;
            cin >> z;
            MAP.insert({z, team});
        }
    }
    for (int i = 0; i < m; i++) {
        int k;
        string z;
        cin >> z;
        cin >> k;
        if (k) {
            cout << MAP[z] << '\n';
        } else {
            for (auto x : MAP) {
                if (x.second == z) cout << x.first << '\n';
            }
        }
    }
}