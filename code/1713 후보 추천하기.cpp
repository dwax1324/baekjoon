#include <bits/stdc++.h>

using namespace std;

// 구현

// 벡터안에 배열값을 넣으면 배열에있는값도 바뀐다고
// 머에 씌인거처럼 단단히착각
// 30분날려버림
// 빠르게 말고 똑똑히 코딩하자

bool cmp(pair<pair<int *, int>, int> &a, pair<pair<int *, int>, int> b) {
    if (*a.first.first == *b.first.first) return a.first.second < b.first.second;
    return *a.first.first < *b.first.first;
}

bool cmp2(pair<pair<int *, int>, int> a, pair<pair<int *, int>, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    int m;
    vector<pair<pair<int *, int>, int>> v;
    cin >> n >> m;
    int score[1001];
    memset(score, 0, sizeof(score));
    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;
        score[a]++;
        bool flag = false;
        for (auto x : v) {
            if (x.second == a) {
                flag = true;
                break;
            }
        }
        if (flag) continue;

        if (v.size() < n) {
            v.push_back({{&score[a], i}, a});
        } else {
            sort(v.begin(), v.end(), cmp);
            // for (auto x : v) cout << *x.first.first << " ";
            // cout << '\n';
            score[v[0].second] = 0;
            v[0] = {{&score[a], i}, a};
        }
    }
    sort(v.begin(), v.end(), cmp2);

    for (auto x : v) {
        cout << x.second << " ";
    }
}