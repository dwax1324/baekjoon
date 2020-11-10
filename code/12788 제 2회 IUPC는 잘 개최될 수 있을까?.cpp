#include <bits/stdc++.h>

// 그냥 내림차정렬후 하나씩 빼주면된다.
// 이게 실버4인가? 난이도 측정기준을 모르겠네

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int a, b;
    cin >> a >> b;
    int teams = a * b;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.rbegin(), v.rend());

    int cnt = 0;
    if (teams > accumulate(v.begin(), v.end(), 0)) {
        cout << "STRESS";
        return 0;
    }
    for (int i = 0; i < v.size(); i++) {
        cnt++;
        teams -= v[i];
        if (teams <= 0) break;
    }
    cout << cnt;
}