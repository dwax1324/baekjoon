#include <bits/stdc++.h>

// 단순구현

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        vector<int> ans;
        bool died = false;
        for (int i = 0; i < x; i++) {
            int ret = -1;
            int sick;
            cin >> sick;
            for (int z = 0; z < n; z++) {
                if (v[z].first == sick) {
                    ret = v[z].second;
                    break;
                }
            }
            if (ret == -1) died = true;
            ans.push_back(ret);
        }
        if (died)
            cout << "YOU DIED\n";
        else {
            for (auto x : ans) {
                cout << x << " ";
            }
            cout << '\n';
        }
    }
}