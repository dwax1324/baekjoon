#include <bits/stdc++.h>
using namespace std;

// 단순구현문제

// 맵사용해서 순서를 기록한다.(중복되면 덮어씌운다)
// 벡터에 값을 집어넣고 정렬시킨다.
// 수강가능인원, 수강한인원 중 작은값만큼 출력한다.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k, l;
    cin >> k >> l;
    map<string, int> MAP;
    vector<int> v;
    int cnt = 0;
    for (int i = 0; i < l; i++) {
        string a;
        cin >> a;
        MAP[a] = ++cnt;
    }

    vector<pair<int, string>> ans;
    for (auto x : MAP) {
        ans.push_back({x.second, x.first});
    }

    sort(ans.begin(), ans.end());
    int MIN = min(k, (int)ans.size());
    for (int i = 0; i < MIN; i++) {
        cout << ans[i].second << '\n';
    }
}