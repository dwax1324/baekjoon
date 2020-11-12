#include <bits/stdc++.h>

using namespace std;

// 단순 구현
// map써서 더 빠르게 풀 수 있을듯
// 스트링 받으면서 번호부여
// 번호가 순서가 맞으면 카운트증가
// 나이브하게 하면 n^3으로 시간초과날듯?

int main() {
    int n;
    cin >> n;
    vector<pair<int, string>> v;
    vector<pair<int, string>> v2;

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        v.push_back({i, a});
    }

    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        for (int j = 0; j < n; j++) {
            if (v[j].second == a) {
                v2.push_back({j, a});
                break;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v2[i].first < v2[j].first) cnt++;
        }
    }
    printf("%d/%d", cnt, (n * (n - 1)) / 2);
}