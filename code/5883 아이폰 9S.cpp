#include <bits/stdc++.h>

// 단순 구현
// 셋에 원소들을 집어넣는다.
// 벡터에서 같은 원소를 빼면서 다른 벡터에 집어넣고
// cnt++을 해준다.
// 굳이 다른 벡터안만들어도 될듯

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v;
    set<int> SET;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
        SET.insert(a);
    }
    int cnt = 0;

    for (auto x : SET) {
        vector<int> cpy;
        for (int j = 0; j < n; j++) {
            if (v[j] != x) {
                cpy.push_back(v[j]);
            }
        }
        cnt = 0;
        for (int j = 0; j < cpy.size() - 1; j++) {
            if (cpy[j] == cpy[j + 1])
                cnt++;
            else {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans + 1;
}