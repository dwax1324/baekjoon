#include <bits/stdc++.h>

// 찾는 투표수가 적은 사람은 필용없을 줄 알았는데 필요했음
// 하나씩 빼고 정렬하는 걸로 했는데 굳이 정렬안하고 max값으로 해도 될듯 우선순위큐

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    int dasom;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cin >> dasom;
            continue;
        }
        int a;
        cin >> a;
        v.push_back(a);
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    int cnt = 0;
    while (1) {
        sort(v.rbegin(), v.rend());
        if (v[0] >= dasom) {
            v[0] -= 1;
            dasom++;
        } else {
            break;
        }
        cnt++;
    }
    cout << cnt;
}